#ifndef __CHANNEL_H__
#define __CHANNEL_H__

namespace sinet
{

class EventLoop;
class Buffer;

class Channel {
public:
    Channel(EventLoop* loop, Buffer* buf): eventLoop(loop), serverChannel(false), buffer(buf) {}
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
    Buffer* buffer;
};

} // namespace sinet


#endif
