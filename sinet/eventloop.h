#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

#include <map>
#include "channel.h"

namespace sinet {

class Selector;

class EventLoop {
public:
    void init();
    void run();
    const std::map<int, Channel*>& getChannels() const { return channels; }
    void addChannel(int fd, Channel* ch);
    void removeChannel(int fd);
    void dispatch(int fd, int revents);
private:
    std::map<int, Channel*> channels;
    Selector* selector;
    bool isStopped;
};

}

#endif
