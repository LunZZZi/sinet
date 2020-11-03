#include "channel.h"
#include "common.h"
#include "eventloop.h"
#include "buffer.h"
#include "log.h"

namespace sinet
{

void Channel::handle(int revents)
{
    debug("channel[%d].handle revents=%d\n", descriptor, revents);

    m_handler.handleEvent(this, revents);
}

} // namespace sinet
