#include "shell.h"
#include "mini_uart.h"

int str_comp (unsigned char *str1, unsigned char *str2) {

  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    ++str1;
    ++str2;
  }
  if (*str1 == '\0' && *str2 == '\0') {
    return 1;
  }
  else {
    return 0;
  }

}


void parse_buf (unsigned char *buf) {

  unsigned char *help     = "help";
  unsigned char *hello    = "hello";
  unsigned char *reboot   = "reboot";

  if (str_comp(buf, help)) {
    mini_uart_write('\n');
    mini_uart_display("help   : print this help menu\n");
    mini_uart_display("hello  : print Hello World!\n");
    mini_uart_display("reboot : reboot the device\n");
    return;
  }

  if (str_comp(buf, hello)) {
    mini_uart_write('\n');
    mini_uart_display("Hello World!\n");
    return;
  }

  mini_uart_write('\n');
  mini_uart_display("The command is not defined\n");

}


void shell_start () {
  
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
        mini_uart_write(user_input);
        continue;
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