#include <fayt/notification.h> 
#include <fayt/syscall.h>
#include <fayt/address_space.h>
#include <fayt/debug.h>
#include <fayt/string.h>

#ifndef DUFAY

int notify_and_block(struct comm_bridge *bridge) {
	if(bridge == NULL) return -1;

	if(bridge->data.ptr) {
		uintptr_t vaddr;
		int ret = as_allocate(&address_space, &vaddr,
			DIV_ROUNDUP(bridge->data.length, PAGE_SIZE));
		memcpy((void*)vaddr, bridge->data.ptr, bridge->data.length);
		bridge->data.ptr = (void*)vaddr;
		if(ret == -1) RETURN_ERROR;
	} else { bridge->data.ptr = NULL; bridge->data.length = 0; }

	struct syscall_response response = SYSCALL1(SYSCALL_NOTIFICATION_BUILD, &bridge);
	if(response.ret == -1) RETURN_ERROR;

	response = SYSCALL1(SYSCALL_NOTIFICATION_BROADCAST, &bridge);
	if(response.ret == -1) RETURN_ERROR;

	return 0;
}

#endif
