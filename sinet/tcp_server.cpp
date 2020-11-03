#include "common.h"
#include "tcp_server.h"
#include "channel_handler.h"
#include "log.h"
#include "common.h"
#include "error.h"

namespace sinet
{

void TCPServer::start(int port)
{
    debug("TCPServer.bind\n");
    int descriptor = socket(AF_INET, SOCK_STREAM, 0);
    
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

    debug("TCPServer.listen\n");
    int rt = ::listen(descriptor, 1024);
    if (rt < 0)
    {
        error("listen failed ");
    }

    ChannelHandler handler(this);
    std::unique_ptr<Channel> channel = std::make_unique<Channel>(descriptor, POLLRDNORM, true, handler);
    m_eventLoop->addChannel(descriptor, std::move(channel));
}

} // namespace sinet
