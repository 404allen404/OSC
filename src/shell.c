#include "shell.h"
#include "mini_uart.h"
#include "string.h"

void set(long addr, unsigned int value) {
  volatile unsigned int *point = (unsigned int*)addr;
  *point = value;
}

void reset(int tick) {              // reboot after watchdog timer expire
  set(PM_RSTC, PM_PASSWORD | 0x20); // full reset
  set(PM_WDOG, PM_PASSWORD | tick); // number of watchdog tick
}

void cancel_reset() {
  set(PM_RSTC, PM_PASSWORD | 0); // full reset
  set(PM_WDOG, PM_PASSWORD | 0); // number of watchdog tick
}


void parse_buf(unsigned char *buf) {

  if(str_cmp(buf, "help")) {
    mini_uart_display("\nhelp   : print this help menu\n");
    mini_uart_display("hello  : print Hello World!\n");
    mini_uart_display("reboot : reboot the device\n");
    return;
  }

  if(str_cmp(buf, "hello")) {
    mini_uart_display("\nHello World!\n");
    return;
  }

  if(str_cmp(buf, "reboot")) {
    mini_uart_display("\nReboot...\n");
    reset(1000000000);
    while(1);
    return;
  }

  mini_uart_display("\nThe command is not defined\n");

}


void shell_start() {
  
  unsigned int buf_p = 0;
  unsigned char user_input_buf[100];
  while (1) {

    mini_uart_display("# ");

    while (1) {

      unsigned char user_input = mini_uart_read();
      if (user_input != '\r') {
        mini_uart_write(user_input);
        user_input_buf[buf_p++] = user_input;
      }

      if (user_input == '\r' && buf_p == 0) {
        mini_uart_write('\n');
        break;
      }

      if (user_input == '\r' && buf_p != 0) {
        user_input_buf[buf_p++] = '\0';
        parse_buf(user_input_buf);
        buf_p = 0;
        break;
      }

    }

  }

}