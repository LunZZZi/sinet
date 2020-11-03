#ifndef __CHANNEL_HANDLER_H__
#define __CHANNEL_HANDLER_H__

namespace sinet
{

class TCPServer;
class Channel;

class ChannelHandler {
public:
    ChannelHandler(TCPServer* server): m_tcpServer(server) {}
    
    void handleEvent(Channel* channel, int revents);
private:

    TCPServer* m_tcpServer;
};

} // namespace sinet

#endif
