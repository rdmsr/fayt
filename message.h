#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <fayt/handle.h>

#include <stddef.h>
#include <stdint.h>

#include <sys/queue.h>

#define PORT_RIGHT_RECV (1 << 0)
#define PORT_RIGHT_SEND (1 << 1)
#define PORT_RIGHT_SEND_ONCE (1 << 2)

struct message_header {
	handle_t destination;
	handle_t reply;
	size_t size;
};

#endif
