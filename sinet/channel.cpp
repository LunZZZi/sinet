#include "channel.h"
#include "common.h"
#include "eventloop.h"
#include "buffer.h"
#include "log.h"

namespace sinet
{

void Channel::bind(int port)
{
    debug("channel.bind\n");
    descriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int rt1 = ::bind(descriptor, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (rt1 < 0)
    {
        error("bind error");
    }
}

void Channel::listen()
{
    debug("channel.listen\n");
    int rt = ::listen(descriptor, 1024);
    if (rt < 0)
    {
        error("listen failed ");
    }
}

void Channel::accept()
{
    debug("channel.accept\n");
}

void Channel::handle(int revents)
{
    debug("channel[%d].handle revents=%d\n", descriptor, revents);
    UNUSED(eventLoop);

    if (serverChannel) 
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int connfd = ::accept(descriptor, (struct sockaddr *) &client_addr, &client_len);
        if (connfd < 0)
        {
            error("accept error");
        }

        debug("open connfd %d\n", connfd);
        Buffer* buffer = new Buffer();
        Channel* ch = new Channel(eventLoop, buffer);
        ch->setDescriptor(connfd);
        ch->setEvents(POLLRDNORM);
        eventLoop->addChannel(connfd, ch);
    }
    else
    {
        int n;
        // fixme
        char buf[1024];
        UNUSED(buffer);
        if (revents & (POLLRDNORM | POLLERR)) {
            if ((n = read(descriptor, buf, 1024)) > 0) {
                if (write(descriptor, buf, n) < 0) {
                    error("write error");
                }
            } else if (n == 0 || errno == ECONNRESET) {
                close(descriptor);
                eventLoop->removeChannel(descriptor);
            } else {
                error("read error");
            }
        }
    }
}

void Channel::error(const char* msg)
{
    fprintf(stderr, "%s", msg);
    exit(-1);
}

} // namespace sinet
