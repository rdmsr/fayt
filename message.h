#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <stddef.h>
#include <sys/queue.h>
#include <stdint.h>

#define PORT_RIGHT_RECV (1 << 0)
#define PORT_RIGHT_SEND (1 << 1)
#define PORT_RIGHT_SEND_ONCE (1 << 2)

typedef uint32_t handle_t;

struct message_header {
	handle_t destination;
	handle_t reply;
	size_t size;
};

#endif