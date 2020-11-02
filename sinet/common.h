#ifndef __COMMON_H__
#define __COMMON_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>       /* timeval */
#include <sys/types.h>
#include <sys/uio.h>
#include <poll.h>
#include <fcntl.h>          /* for nonblocking */
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdio>
#include <errno.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <string.h>

namespace sinet {

template <typename T>
void UNUSED(T &&)
{ }
    
}

#endif