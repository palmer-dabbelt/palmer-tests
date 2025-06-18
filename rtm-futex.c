#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#ifndef SYS_futex
#define SYS_futex SYS_futex_time64
#endif

long futex(uint32_t *uaddr, int futex_op, uint32_t val,
           const struct timespec *timeout,
           uint32_t *uaddr2, uint32_t val3) {
    return syscall(SYS_futex, uaddr, futex_op, val, timeout, uaddr2, val3);
}

int main(){
  futex((void*) 0x1ffffff81300000, FUTEX_WAIT, 0, 0, 0, 0);
  return 0;
}
