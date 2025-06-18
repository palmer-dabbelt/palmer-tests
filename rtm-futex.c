#include <linux/futex.h>

main(){
  futex((void*) 0x1ffffff81300000, FUTEX_WAIT, 0, 0, 0, 0);
}
