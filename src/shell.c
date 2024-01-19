#include "shell.h"
#include "mini_uart.h"

void shell_start () {
  
  while (1) {
    
    mini_uart_display("# ");

    while (1) {
      unsigned char user_input = mini_uart_read();
      mini_uart_write(user_input);
    }

  }

}