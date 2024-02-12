#ifndef __STRING_H__
#define __STRING_H__

unsigned int str_cmp(unsigned char* str1, unsigned char* str2);
unsigned int str_len(unsigned char* str);
void uint_to_str(unsigned int num, unsigned char* str, unsigned int radix);
void str_rev(unsigned char* str);

#endif