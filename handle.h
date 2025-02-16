#ifndef FAYT_HANDLE_H_
#define FAYT_HANDLE_H_

#include <stdint.h>

#define HANDLE_ACCESS_READ (1 << 0)
#define HANDLE_ACCESS_WRITE (1 << 1)

typedef uint32_t handle_t;

enum { HANDLE_CLASS_BLK };

struct handle_blk {
	size_t lba_start;
	size_t lba_cnt;
	size_t lba_size;

	void *private;
};

#endif
