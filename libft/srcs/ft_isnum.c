#include "libft.h"

int ft_isnum(char *str)
{
  char  *s;
  int   ret;

  s = str;
  ret = 0;
  while (*s == ' ')
    s++;
  if (*s == '+' || *s == '-')
    s++;
  while (*s)
  {
    if(*s < '0' || *s > '9')
      return (0);
    else
      ret = 1;
    s++;
  }
  return (ret);
}