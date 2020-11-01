#include "buffer.h"
#include <cassert>
#include <cstdio>

namespace sinet {

Buffer::~Buffer() 
{
    if (!data) {
        free(data);
    }
}

void Buffer::alloc(size_t n)
{
    assert(!data && n > 0);
    data = (char *)malloc(n * sizeof(char));
    dataLength = n;
}

size_t Buffer::writePosition()
{
    assert(dataLength > writeIndex);
    assert(readIndex <= writeIndex);
    return writeIndex;
}

void Buffer::appendData(char c)
{
    // TODO: auto increase
    assert(writeIndex + 1 < dataLength);
    data[writeIndex++] = c;
}

}