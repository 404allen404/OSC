extern unsigned long __bss_start;
extern unsigned long __bss_end;
extern unsigned long __stack_top;

void bootloader () {

  // Set the stack pointer

  // Initialize the bss segment
  unsigned long *bss_ptr = &__bss_start;
  while (bss_ptr < &__bss_end) {
      *bss_ptr = 0;
      ++bss_ptr;
  }

}

void _start () {

  bootloader();

}