#include "mini_uart.h"
#include "shell.h"
#include "mailbox.h"

int main () {

  //Initialize the mini uart
  mini_uart_init();

  get_board_revision();
  get_arm_memory();

  //Start shell
  shell_start();

  return 0;
  
}