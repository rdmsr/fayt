#ifndef FAYT_IRQ_H_
#define FAYT_IRQ_H_

#include <fayt/lock.h>

#include <stdint.h>

struct anchor {
	int identifier;

	uint64_t paddr;

	struct anchor *next;
	struct anchor *last;

	int refcnt;
	struct spinlock lock;
};

#endif
