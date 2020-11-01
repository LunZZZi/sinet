#include "channel.h"
#include "common.h"

namespace sinet
{

void Channel::bind()
{
    printf("channel.bind\n");
}

void Channel::listen()
{
    printf("channel.listen\n");
}

void Channel::accept()
{
    printf("channel.accept\n");
}

void Channel::handle(int revents)
{
    printf("channel[%d].handle revents=%d\n", descriptor, revents);
}

} // namespace sinet
