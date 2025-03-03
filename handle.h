#ifndef FAYT_HANDLE_H_
#define FAYT_HANDLE_H_

#include <fayt/sched.h>

#include <stdint.h>

#define HANDLE_ACCESS_READ (1 << 0)
#define HANDLE_ACCESS_WRITE (1 << 1)

#define HANDLE_AS 0
#define HANDLE_MSG_INIT 1
#define HANDLE_MSG_NOTIF 2

typedef uint32_t handle_t;

enum { HANDLE_CLASS_BLK, HANDLE_CLASS_NOTIFICATION_CHANNEL };

struct blk_hdl {
	size_t lba_start;
	size_t lba_cnt;
	size_t lba_size;

	void *private;
};

struct notif_channel_hdl {
	struct sched_proc_id proc_id;
};

#endif
