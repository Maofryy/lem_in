#include "libft.h"

int ft_min(int a, int b)
{
  if (a < b)
    return (a);
  else
    return (b);
}

int ft_max(int a, int b)
{
  if (a > b)
    return (a);
  else
    return (b);
}

int ft_abs(int n)
{
  if (n < 0)
    return (-n);
  else
    return (n);
}
