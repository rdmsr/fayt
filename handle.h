#ifndef FAYT_HANDLE_H_
#define FAYT_HANDLE_H_

#include <fayt/sched.h>

#include <stdint.h>

#define HANDLE_ACCESS_READ (1 << 0)
#define HANDLE_ACCESS_WRITE (1 << 1)

typedef uint32_t handle_t;

enum { CAPABILITY_SELF_AS, CAPABILITY_SELF_SCHED };
enum { HANDLE_CLASS_BLK, HANDLE_CLASS_NOTIFICATION_CHANNEL };

#endif
