#include "selector.h"
#include "common.h"
#include "channel.h"

namespace sinet {

void Selector::update()
{
    const std::map<int, Channel> channels = eventLoop->getChannels();
    for (auto entry = channels.begin(); entry != channels.end(); entry++) {
        printf("selector: create poll_fd [fd=%d]\n", entry->first);
    }
}

void Selector::select()
{
    printf("poll fd=0 event=Accept\n");
    eventLoop->dispatch(0, 123);
}

}