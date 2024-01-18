void _start() __attribute__((section(".text")));

extern unsigned long __bss_start;
extern unsigned long __bss_end;
extern unsigned long __stack_top;

void _start () {

  // Set the stack pointer
  asm volatile ("ldr x0, =_start");
  asm volatile ("mov sp, x0");

  // Initialize the bss segment
  unsigned long *bss_ptr = &__bss_start;
  while (bss_ptr < &__bss_end) {
      *bss_ptr = 0;
      ++bss_ptr;
  }

  while(1);

}