#include "sinet/common.h"
#include "sinet/buffer.h"

int main(int argc, char const *argv[])
{
    sinet::Buffer buffer;
    buffer.alloc(10);
    buffer.appendData('f');
    printf("write position = %zu\n", buffer.writePosition());
    return 0;
}
