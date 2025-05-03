#ifndef FAYT_SCHED_H_
#define FAYT_SCHED_H_

#include <fayt/capability.h>
#include <fayt/bitmap.h>
#include <fayt/dictionary.h>
#include <fayt/time.h>

constexpr int ARCHCTL_SCHED_ACQUIRE = 1;
constexpr int ARCHCTL_SCHED_RELEASE = 2;
constexpr int ARCHCTL_RESERVE_IRQ = 3;
constexpr int ARCHCTL_RELEASE_IRQ = 4;
constexpr int ARCHCTL_YIELD = 5;

constexpr int FUTEX_WAIT = 1;
constexpr int FUTEX_WAKE = 2;

#endif
