#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include <vector>
#include <poll.h>

namespace sinet
{

class Selector {
public:
    Selector() {}
    void add(int fd, int events);
    void remove(int fd);
    std::vector<pollfd> select();
private:
    std::vector<pollfd> eventSet;
};

} // namespace sinet


#endif
