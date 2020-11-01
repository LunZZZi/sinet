#ifndef __CHANNEL_H__
#define __CHANNEL_H__

namespace sinet
{

class Channel {
public:
    Channel() {}
    void bind();
    void listen();
    void accept();
    void handle(int revents);
    int getDescriptor() const { return descriptor; }
private:
    int descriptor;
    // int events;
};

} // namespace sinet


#endif
