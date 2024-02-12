#include "mini_uart.h"
#include "gpio.h"

void mini_uart_init() {

  *(unsigned int *)AUXENB          = 1;   //Enable mini UART
  *(unsigned int *)AUX_MU_CNTL_REG = 0;   //Disable transmitter and receiver
  *(unsigned int *)AUX_MU_IER_REG  = 0;   //Disable interrupt
  *(unsigned int *)AUX_MU_IIR_REG  = 6;   //No FIFO
  *(unsigned int *)AUX_MU_LCR_REG  = 3;   //Set the data size to 8-bit 
  *(unsigned int *)AUX_MU_MCR_REG  = 0;   //Don't need auto flow control
  *(unsigned int *)AUX_MU_BAUD     = 270; //Set baud rate to 115200

  //Configure GPFSELn register to change alternate function
  *(unsigned int *)GPFSEL1 = (2 << 12) | (2 << 15);

  //Configure pull up/down register to disable GPIO pull up/down
  *(unsigned int *)GPPUD = 0;

  //Wait 150 cycles
  for (int i = 0 ; i < 150 ; ++i) {
    asm volatile ("nop");
  }

  *(unsigned int *)GPPUDCLK0 = 0x3 << 14;
  *(unsigned int *)GPPUDCLK1 = 0;

  //Wait 150 cycles
  for (int i = 0 ; i < 150 ; ++i) {
    asm volatile ("nop");
  }

  //Write to GPPUD to remove the control signal
  *(unsigned int *)GPPUD = 0;
  //Write to GPPUDCLK0/1 to remove the clock 
  *(unsigned int *)GPPUDCLK0 = 0;
  *(unsigned int *)GPPUDCLK1 = 0;

  *(unsigned int *)AUX_MU_CNTL_REG = 3; //Enable the transmitter and receiver

}

unsigned char mini_uart_read() {

  while (!(*(unsigned int *)AUX_MU_LSR_REG & 0x1));
  return *(unsigned char *)AUX_MU_IO_REG;

}

void mini_uart_write(unsigned char c) {

  //'\r' represent enter
  //'\n' represent change line
  if (c == '\r') {
    while (!(*(unsigned int *)AUX_MU_LSR_REG & 0x20));
    mini_uart_display("\n# ");
    return;
  }

  while (!(*(unsigned int *)AUX_MU_LSR_REG & 0x20));
  *(unsigned char *)AUX_MU_IO_REG = c;

}

void mini_uart_display(unsigned char* s) {
  
  while (*s) {
    mini_uart_write(*s);
    ++s;
  }

}