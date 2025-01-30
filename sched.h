#ifndef FAYT_SCHED_H_ 
#define FAYT_SCHED_H_

#include <fayt/time.h>

constexpr int SCHED_RESERVED_CID = 0x20;
constexpr int SCHED_TICK_RATE_MS = 20;
constexpr int NOT_SCHED_ENQUEUE = 1;
constexpr int NOT_SCHED_DEQUEUE = 2;

struct sched_descriptor {
	struct timer timer;
	int processor_id;
	int queue_default_refill;
	int load;
	int cid;
	struct time slice;
};

struct sched_queue_config {
	int cid;
	int cgroup;
	int nice;
	int offload;
	int phantom_runtime;
	int flags;
};

struct sched_queue_config_set {
	int cnt;
	struct sched_queue_config config[];
};

struct sched_queue_entry {
	int cid;
	int asid;
};

#endif
