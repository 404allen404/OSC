#ifndef __MINI_UART_H__
#define __MINI_UART_H__

#define AUXENB          0x3F215004
#define AUX_MU_IO_REG   0x3F215040
#define AUX_MU_IER_REG  0x3F215044
#define AUX_MU_IIR_REG  0x3F215048
#define AUX_MU_LCR_REG  0x3F21504C
#define AUX_MU_MCR_REG  0x3F215050
#define AUX_MU_LSR_REG  0x3F215054
#define AUX_MU_CNTL_REG 0x3F215060
#define AUX_MU_BAUD     0x3F215068

void mini_uart_init();
unsigned char mini_uart_read();
void mini_uart_write(unsigned char c);
void mini_uart_display(unsigned char* s);

#endif