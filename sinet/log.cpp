#include "log.h"
#include <stdarg.h>
#include "common.h"

namespace sinet {

void debug(const char* format, ...)
{
    UNUSED(format);
    #ifdef ENABLE_DEBUG
    printf("[msg] ");
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stdout, format, argptr);
    va_end(argptr);
    #endif
}

}