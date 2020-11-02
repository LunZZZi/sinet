#include "selector.h"
#include "common.h"
#include "channel.h"
#include "log.h"
#include <vector>

namespace sinet {

void Selector::add(int fd, int events)
{
    debug("selector add %d %d\n", fd, events);
    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = events;
    eventSet.push_back(pfd);
}

void Selector::remove(int fd)
{
    debug("selector erase %d\n", fd);
    for (auto it = eventSet.begin(); it != eventSet.end(); it++) {
        if (it->fd == fd) {
            it->fd = -1;
            break;
        }
    }
}

void Selector::select()
{
    size_t size = eventSet.size();
    debug("select size %zu\n", size);
    int ready = poll(eventSet.data(), size, -1);
    debug("poll return %d\n", ready);
    if (ready < 0) {
        fprintf(stderr, "poll error\n");
        exit(-1);
    }
    for (size_t it = 0; it != size; it++) {
        if (eventSet[it].revents & POLLRDNORM) {
            eventLoop->dispatch(eventSet[it].fd, eventSet[it].revents);
        }
    }
}

}