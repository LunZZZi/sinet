#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include "eventloop.h"
#include <vector>
#include <poll.h>

namespace sinet
{

class Selector {
public:
    Selector(EventLoop* loop): eventLoop(loop) {}
    void add(int fd, int events);
    void remove(int fd);
    void select();
private:
    EventLoop* eventLoop;
    std::vector<pollfd> eventSet;
};

} // namespace sinet


#endif
