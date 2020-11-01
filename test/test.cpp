#include "sinet/common.h"
#include "sinet/buffer.h"
#include "sinet/eventloop.h"

int main(int argc, char const *argv[])
{
    sinet::UNUSED(argc);
    sinet::UNUSED(argv);
    sinet::EventLoop loop;
    loop.init();
    loop.run();
    return 0;
}
