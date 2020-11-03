#include "eventloop.h"
#include "selector.h"
#include "common.h"
#include "buffer.h"

namespace sinet
{

void EventLoop::init()
{
    std::unique_ptr<Channel> channel = std::make_unique<Channel>(this, std::make_unique<Buffer>());
    channel->setServerChannel();
    channel->bind(9877);
    channel->listen();
    channel->setEvents(POLLRDNORM);
    addChannel(channel->getDescriptor(), std::move(channel));
}

void EventLoop::run()
{
    while (!isStopped) {
        auto fds = selector->select();
        for (auto it = fds.begin(); it != fds.end(); it++) {
            printf("dispatch %d %d\n", it->fd, it->revents);
            dispatch(it->fd, it->revents);
        }
    }
}

void EventLoop::dispatch(int fd, int revents)
{
    Channel& ch = *channels[fd];
    ch.handle(revents);
}

void EventLoop::addChannel(int fd, std::unique_ptr<Channel> ch)
{
    int events = ch->getEvents();
    channels[fd] = std::move(ch);
    selector->add(fd, events);
}

void EventLoop::removeChannel(int fd)
{
    channels.erase(fd);
    selector->remove(fd);
}

} // namespace sinet
