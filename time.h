#ifndef FAYT_TIME_H_
#define FAYT_TIME_H_

#include <stdint.h>
#include <stddef.h>

#define NANO_PER_SECOND 1000000000

typedef int64_t time_t;
typedef int64_t freq_t;

struct time {
	time_t sec;
	time_t nsec;
};

#define TIME_SOURCE_INVARIANT_TSC 1
#define TIME_SOURCE_HPET 2

struct timer {
	int source;
	freq_t freq;
	struct time (*read)(struct timer*);
};

struct time time_add(struct time, struct time);
struct time time_sub(struct time, struct time);
struct time time_convert(struct timer*, time_t);

struct time invariant_tsc_read(struct timer *timer);

#endif
