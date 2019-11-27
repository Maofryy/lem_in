//add stdheader

#include "libft.h"

char		*ft_strnjoinfree(char *s1, char *s2, size_t n)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strncat(ret, s2, n);
	ft_strdel(&s1);
	return (ret);
}
