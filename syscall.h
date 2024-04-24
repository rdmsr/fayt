#ifndef FAYT_SYSCALL_H_
#define FAYT_SYSCALL_H_

#include <stdint.h>
#include <stddef.h>

struct syscall_response {
    int ret; 
    int code;
};

#define SYSCALL0(NUM) ({ \
    struct syscall_response _response; \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM) \
                  : "rcx", "r11", "memory"); \
    _response; \
})

#define SYSCALL1(NUM, ARG0) ({ \
    struct syscall_response _response; \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0) \
                  : "rcx", "r11", "memory"); \
    _response; \
})

#define SYSCALL2(NUM, ARG0, ARG1) ({ \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0), "S"(ARG1) \
                  : "rcx", "r11", "memory"); \
})

#define SYSCALL3(NUM, ARG0, ARG1, ARG2) ({ \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0), "S"(ARG1), "d"(ARG2) \
                  : "rcx", "r11", "memory"); \
})

#define SYSCALL4(NUM, ARG0, ARG1, ARG2, ARG3) ({ \
    register uint64_t arg3 asm("r10") = (uint64_t)ARG3; \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0), "S"(ARG1), "d"(ARG2), \
                    "r"(arg3) \
                  : "rcx", "r11", "memory"); \
})

#define SYSCALL5(NUM, ARG0, ARG1, ARG2, ARG3, ARG4) ({ \
    register uint64_t arg3 asm("r10") = (uint64_t)ARG3; \
    register uint64_t arg4 asm("r8") = (uint64_t)ARG4; \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0), "S"(ARG1), "d"(ARG2), \
                    "r"(arg3), "r"(arg4) \
                  : "rcx", "r11", "memory"); \
})

#define SYSCALL6(NUM, ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) ({ \
    register uint64_t arg3 asm("r10") = (uint64_t)ARG3; \
    register uint64_t arg4 asm("r8")  = (uint64_t)ARG4; \
    register uint64_t arg5 asm("r9")  = (uint64_t)ARG5; \
    asm volatile ("syscall" \
                  : "=a"(_response.ret), "=d"(_response.code) \
                  : "a"(NUM), "D"(ARG0), "S"(ARG1), "d"(ARG2), \
                    "r"(arg3), "r"(arg4), "r"(arg5) \
                  : "rcx", "r11", "memory"); \
})

#define SYSCALL_LOG 0

#endif
