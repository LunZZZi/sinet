#include "tcp_server.h"
#include "channel_handler.h"
#include "channel.h"
#include "common.h"
#include "log.h"

namespace sinet
{

void ChannelHandler::handleEvent(Channel* channel, int revents)
{
    if (channel->getServerChannel()) 
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int connfd = ::accept(channel->getDescriptor(), (struct sockaddr *) &client_addr, &client_len);
        if (connfd < 0)
        {
            printf("accept error");
            exit(-1);
        }

        debug("open connfd %d\n", connfd);
        std::unique_ptr<Channel> ch = std::make_unique<Channel>(connfd, POLLRDNORM, false, *this);
        m_tcpServer->m_eventLoop->addChannel(connfd, std::move(ch));
    }
    else
    {
        int n;
        // fixme
        char buf[1024];
        if (revents & (POLLRDNORM | POLLERR)) {
            if ((n = read(channel->getDescriptor(), buf, 1024)) > 0) {
                if (write(channel->getDescriptor(), buf, n) < 0) {
                    printf("write error");
                    exit(-1);
                }
            } else if (n == 0 || errno == ECONNRESET) {
                close(channel->getDescriptor());
                m_tcpServer->m_eventLoop->removeChannel(channel->getDescriptor());
            } else {
                printf("read error");
                exit(-1);
            }
        }
    }
}

} // namespace sinet
