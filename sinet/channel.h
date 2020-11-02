#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include <memory>
#include "buffer.h"

namespace sinet
{

class EventLoop;

class Channel {
public:
    Channel(EventLoop* loop, std::unique_ptr<Buffer> buf)
        : eventLoop(loop), serverChannel(false), buffer(std::move(buf)) {}
    void bind(int port);
    void listen();
    void accept();
    void handle(int revents);
    void setServerChannel() { serverChannel = true; };
    void setDescriptor(int fd) { descriptor = fd; };
    void setEvents(int evt) { events = evt; }
    int getDescriptor() const { return descriptor; }
    int getEvents() { return events; };
private:
    void error(const char* msg);

    int descriptor;
    int events;
    EventLoop* eventLoop;
    bool serverChannel;
    std::unique_ptr<Buffer> buffer;
};

} // namespace sinet


#endif
