#include "common.h"

namespace sinet
{

inline void error(const char* msg)
{
    fprintf(stderr, "%s", msg);
    exit(-1);
}

} // namespace sinet
