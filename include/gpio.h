#ifndef __GPIO_H__
#define __GPUIO_H__

//GPIO Alternate function select register
#define GPFSEL0   0x3F200000
#define GPFSEL1   0x3F200004
#define GPFSEL2   0x3F200008
#define GPFSEL3   0x3F20000C
#define GPFSEL4   0x3F200010
#define GPFSEL5   0x3F200014

#define GPSET0    0x3F20001C
#define GPSET1    0x3F200020

#define GPCLR0    0x3F200028
#define GPCLR1    0x3F20002C

#define GPLEV0    0x3F200034
#define GPLEV1    0x3F200038

#define GPEDS0    0x3F200040 
#define GPEDS1    0x3F200044

#define GPREN0    0x3F20004C 
#define GPREN1    0x3F200050

#define GPFEN0    0x3F200058
#define GPFEN1    0x3F20005C

#define GPHEN0    0x3F200064
#define GPHEN1    0x3F200068

#define GPLEN0    0x3F200070
#define GPLEN1    0X3F200074

#define GPAREN0   0x3F20007C
#define GPAREN1   0X3F200080

#define GPAFEN0   0x3F200088 
#define GPAFEN1   0x3F20008C

#define GPPUD     0x3F200094
#define GPPUDCLK0 0x3F200098
#define GPPUDCLK1 0X3F20009C

#endif