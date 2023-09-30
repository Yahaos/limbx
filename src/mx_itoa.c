#include "libmx.h"

char *mx_itoa(int num) {
  char *n_str = NULL;
  if (num == 0)
  {
    n_str = mx_strnew(1);
    n_str[0] = '0';
    return n_str;
  }
  int length = 0;
  long long num = num;
  if (num < 0) 
  {
    length++;
    num *= -1;
  }

  while (num != 0) 
  {
    num /= 10;
    length++;
  }

  n_str = mx_strnew(length);
  if (num < 0)
  {
    n_str[0] = '-';
    num *= -1;
  }
  n_str[length--] = '\0';

  while ((num != 0 && length >= 0) && n_str[length] != '-')
  {
    n_str[length--] = (num % 10) + '0';
    num /= 10;
  }

  return n_str;
}
