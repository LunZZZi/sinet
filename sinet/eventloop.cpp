#include "eventloop.h"
#include "selector.h"
#include "common.h"
#include "buffer.h"

namespace sinet
{

void EventLoop::init()
{
    Buffer* buffer = new Buffer();
    Channel* channel = new Channel(this, buffer);
    channel->setServerChannel();
    channel->bind(9877);
    channel->listen();
    channel->setEvents(POLLRDNORM);
    selector = new Selector(this);
    addChannel(channel->getDescriptor(), channel);
}

void EventLoop::run()
{
    while (!isStopped) {
        selector->select();
    }
}

void EventLoop::dispatch(int fd, int revents)
{
    Channel* ch = channels[fd];
    ch->handle(revents);
}

void EventLoop::addChannel(int fd, Channel* ch)
{
    channels[fd] = ch;
    selector->add(fd, ch->getEvents());
}

void EventLoop::removeChannel(int fd)
{
    channels.erase(fd);
    selector->remove(fd);
}

} // namespace sinet
