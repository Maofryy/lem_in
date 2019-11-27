#include "libft.h"

char		*ft_lltoa_baset(long long n, int base)
{
	int		i;
	char	*str;

	if (n < 0)
	{
		str = ft_ulltoa_base((unsigned long long)-n, base);
		i = ft_strlen(str);
		ft_reverse_str(str, i);
		str[i++] = '-';
		ft_reverse_str(str, i);
		str[i] = '\0';
	}
	else
		str = ft_ulltoa_base((unsigned long long)n, base);
	return (str);
}
