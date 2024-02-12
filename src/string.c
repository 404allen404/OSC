#include "string.h"

int str_cmp(unsigned char *str1, unsigned char *str2) {

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