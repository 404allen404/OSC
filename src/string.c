#include "string.h"

unsigned int str_cmp(unsigned char *str1, unsigned char *str2) {

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

void uint_to_str(unsigned int num, unsigned char* str, unsigned int radix) {

  unsigned int digit;
  unsigned int i = 0;
  do {
    digit = num % radix;
    if(digit < 0xA) {
      str[i++] = '0' + digit;
    }
    else {
      str[i++] = 'A' + digit - 0xA;
    }
    num /= radix; 
  } while(num);
  str[i] = '\0';
  str_rev(str);

}

unsigned int str_len(unsigned char* str) {
  unsigned int len = 0;
  while(*str != '\0') {
    ++len;
    ++str;
  }
  return len;
} 

void str_rev(unsigned char* str) {

  unsigned int len = str_len(str);

  if(len == 1) { return; }

  for(unsigned i = 0, j = len - 1; i < j; ++i, --j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }

}