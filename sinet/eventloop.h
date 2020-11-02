#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

#include <map>
#include "channel.h"
#include "selector.h"

namespace sinet {

class EventLoop {
public:
    void init();
    void run();
    // const std::map<int, Channel*>& getChannels() const { return channels; }
    void addChannel(int fd, std::unique_ptr<Channel> ch);
    void removeChannel(int fd);
    void dispatch(int fd, int revents);
private:
    std::map<int, std::unique_ptr<Channel>> channels;
    std::unique_ptr<Selector> selector;
    bool isStopped;
};

}

#endif
