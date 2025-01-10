#ifndef FAYT_NOTIFICATION_H_
#define FAYT_NOTIFICATION_H_

constexpr int SCHED_ENQUEUE = 1;
constexpr int SCHED_DEQUEUE = 2;

constexpr int PCI_BAR = 1;

constexpr int NOTIFY_WEIGHT_SCHEDULED = (1 << 0);
constexpr int NOTIFY_WEIGHT_TICK = (1 << 1);
constexpr int NOTIFY_WEIGHT_INSTANTANEOUS = (1 << 2);

struct comm_bridge {
	int not;

	int cid;
	int cgroup;
	int weight;

	struct {
		void *base;
		int limit;
	} data;

	const char *namespace;
	const char *destination;

	int lnkidx;
};

struct notification_info {

}; 

struct notification_action {
	void (*handler)(struct notification_info*, void*, int);
};

int notify(struct comm_bridge*);

#endif
