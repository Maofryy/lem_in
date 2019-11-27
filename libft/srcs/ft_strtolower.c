#include "libft.h"

char	*ft_strtolower(char *s)
{
	char	*str;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 'Z' && str[i] > 'A')
			str[i] += 32;
	}
	return (str);
}
