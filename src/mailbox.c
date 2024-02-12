#include "mailbox.h"
#include "mini_uart.h"
#include <stdio.h>

void get_board_revision() {
  unsigned int mailbox[7] __attribute__((aligned(16)));
  mailbox[0] = 7 * 4;              //buffer size in bytes
  mailbox[1] = REQUEST_CODE;
  //tags begin
  mailbox[2] = GET_BOARD_REVISION; //tag identifier
  mailbox[3] = 4;                  //value buffer size in bytes
  mailbox[4] = TAG_REQUEST_CODE;
  mailbox[5] = 0;                  //value buffer
  //tags end
  mailbox[6] = END_TAG;

  mailbox_call(mailbox);           //message passing procedure call
  
  mini_uart_display("Get board revision\n");
  //it should be 0xa020d3 for rpi3 b+
  //printf("  board revision: 0x%x\n", mailbox[5]);
}

void get_arm_memory() {
  unsigned int mailbox[8] __attribute__((aligned(16)));
  mailbox[0] = 8 * 4;              //buffer size in bytes
  mailbox[1] = REQUEST_CODE;
  //tags begin
  mailbox[2] = GET_ARM_MEMORY;     //tag identifier
  mailbox[3] = 8;                  //value buffer size in bytes
  mailbox[4] = TAG_REQUEST_CODE;
  mailbox[5] = 0;                  //value buffer
  mailbox[6] = 0;                  //value buffer
  //tags end
  mailbox[7] = END_TAG;

  mailbox_call(mailbox);           //message passing procedure call

  mini_uart_display("Get ARM memoey\n");
  //printf("  base address in bytes: 0x%x\n", mailbox[5]);
  //printf("  size in bytes: %u\n", mailbox[6]);
}

void mailbox_call(unsigned int* mailbox) {
  unsigned int combine_addr = ((unsigned long int)mailbox & 0xFFFFFFF0) | 0x8;
  while(*(unsigned int*)MAILBOX_STATUS & MAILBOX_FULL);
  *(unsigned int*)MAILBOX_WRITE = combine_addr;

  while(1) {
    while(*(unsigned int*)MAILBOX_STATUS & MAILBOX_EMPTY);
    if(*(unsigned int*)MAILBOX_READ == combine_addr) { return; }
  }
}