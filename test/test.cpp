#include "sinet/common.h"
#include "sinet/buffer.h"
#include "sinet/eventloop.h"
#include "sinet/selector.h"

int main(int argc, char const *argv[])
{
    sinet::UNUSED(argc);
    sinet::UNUSED(argv);
    sinet::Selector selector;
    sinet::EventLoop loop(&selector);
    loop.init();
    loop.run();
    return 0;
}
