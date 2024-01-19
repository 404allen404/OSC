#include "mini_uart.h"
#include "shell.h"

int main () {

  //Initialize the mini uart
  mini_uart_init();

  //Start shell
  shell_start();

  return 0;
  
}