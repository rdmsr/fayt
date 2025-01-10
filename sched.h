#ifndef FAYT_SCHED_H_ 
#define FAYT_SCHED_H_

constexpr int NOT_SCHED_ENQUEUE = 1;
constexpr int NOT_SCHED_DEQUEUE = 2;

struct sched_common {
	int blocked;
};

#endif
