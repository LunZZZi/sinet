#include "sinet/common.h"
#include "sinet/buffer.h"
#include "sinet/eventloop.h"
#include "sinet/selector.h"
#include "sinet/tcp_server.h"

using namespace sinet;

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    Selector selector;
    EventLoop loop(&selector);
    TCPServer server(&loop);
    server.start(9877);
    loop.run();
    return 0;
}
