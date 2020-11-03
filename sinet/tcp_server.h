#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

#include "eventloop.h"

namespace sinet
{

class TCPServer 
{
public:
    TCPServer(EventLoop* eventLoop)
        : m_eventLoop(eventLoop) 
    {}

    void start(int port);

    EventLoop* m_eventLoop;
private:
};

} // namespace sinet


#endif
