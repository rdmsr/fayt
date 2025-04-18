#ifndef FAYT_HANDLE_H_
#define FAYT_HANDLE_H_

#include <stdint.h>

#define HANDLE_ACCESS_READ (1 << 0)
#define HANDLE_ACCESS_WRITE (1 << 1)

typedef uint32_t capability_t;

enum { CAPABILITY_SELF_AS, CAPABILITY_SELF_SCHED };

#endif
