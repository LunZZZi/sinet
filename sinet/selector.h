#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include "eventloop.h"

namespace sinet
{

class Selector {
public:
    Selector(EventLoop* loop): eventLoop(loop) {}
    void update();
    void select();
private:
    EventLoop* eventLoop;
};

} // namespace sinet


#endif
