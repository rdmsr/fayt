#include <fayt/notification.h> 
#include <fayt/syscall.h>
#include <fayt/address_space.h>
#include <fayt/debug.h>
#include <fayt/string.h>

#ifndef DUFAY

int notify(struct comm_bridge *bridge) {
	if(bridge == NULL) return -1;

	return 0;
}

#endif
