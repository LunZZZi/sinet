#include "eventloop.h"
#include "selector.h"

namespace sinet
{

void EventLoop::init()
{
    Channel channel;
    channel.bind();
    channel.listen();
    addChannel(channel.getDescriptor(), channel);
    selector = new Selector(this);
    selector->update();
}

void EventLoop::run()
{
    selector->select();
}

void EventLoop::dispatch(int fd, int revents)
{
    Channel& ch = channels[fd];
    ch.handle(revents);
}

} // namespace sinet
