#ifndef FAYT_TIME_H_
#define FAYT_TIME_H_

#include <stdint.h>
#include <stddef.h>

static inline uint64_t rdtsc(void) {
	uint64_t rax, rdx;
	__asm__ volatile ("rdtsc" : "=a"(rax), "=d"(rdx));
	return (uint64_t)rax | ((uint64_t)rdx << 32);
}

#endif
