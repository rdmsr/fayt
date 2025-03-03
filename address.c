#include <fayt/address.h>
#include <fayt/syscall.h>
#include <fayt/debug.h>

int as_allocate(handle_t handle, uintptr_t *address, size_t length)
{
	struct syscall_response syscall_response = SYSCALL4(
		SYSCALL_AS_ACTION, handle, AS_ACTION_ALLOCATE, address, length);
	if (syscall_response.ret == -1)
		RETURN_ERROR;
	return syscall_response.ret;
}

int as_free(handle_t handle, uintptr_t address, size_t length)
{
	struct syscall_response syscall_response =
		SYSCALL4(SYSCALL_AS_ACTION, handle, AS_ACTION_FREE, address, length);
	if (syscall_response.ret == -1)
		RETURN_ERROR;
	return syscall_response.ret;
}
