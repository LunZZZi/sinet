#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <memory>
#include "buffer.h"
#include "channel_handler.h"

namespace sinet
{

class EventLoop;

class Channel {
public:
    Channel(int _fd, int _events, bool _server, ChannelHandler handler)
        : descriptor(_fd), events(_events), serverChannel(_server), m_handler(handler) {}
    void handle(int revents);
    void setServerChannel() { serverChannel = true; };
    int getDescriptor() const { return descriptor; }
    int getEvents() { return events; };
    bool getServerChannel() { return serverChannel; };
private:
    int descriptor;
    int events;
    bool serverChannel;
    ChannelHandler m_handler;
};

} // namespace sinet


#endif
