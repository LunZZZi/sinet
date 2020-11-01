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
    const std::map<int, Channel>& getChannels() const { return channels; }
    void addChannel(int fd, const Channel& ch);
    void dispatch(int fd, int revents);
private:
    std::map<int, Channel> channels;
    Selector* selector;
};

inline void EventLoop::addChannel(int fd, const Channel& ch)
{
    channels[fd] = ch;
}

}

#endif
