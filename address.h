#ifndef FAYT_ADDRESS_H_
#define FAYT_ADDRESS_H_

#include <fayt/handle.h>

#include <stddef.h>
#include <stdint.h>

#define PAGE_SIZE 0x1000ull

enum { AS_ACTION_CONSTRUCT, AS_ACTION_ALLOCATE, AS_ACTION_FREE };

int as_allocate(handle_t handle, uintptr_t *, size_t);
int as_free(handle_t handle, uintptr_t, size_t);

#endif
