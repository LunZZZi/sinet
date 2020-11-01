#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <cstdlib>

#define INIT_BUFFER_SIZE 1024

namespace sinet {

class Buffer {
public:
    Buffer(): dataLength(0), readIndex(0), writeIndex(0) {}
    ~Buffer();

    void alloc(size_t n);
    
    size_t writePosition();

    void appendData(char c);
private:
    char *data;
    size_t dataLength;
    size_t readIndex;
    size_t writeIndex;
};

}

#endif
