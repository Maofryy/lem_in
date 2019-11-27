/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:42:33 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/13 17:44:16 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*str;
	char			*ret;
	unsigned int	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (str[i])
		i++;
	if ((ret = ft_strnew(i)) == NULL)
		return (NULL);
	j = 0;
	while (str[j])
	{
		ret[j] = (*f)(j, str[j]);
		j++;
	}
	return (ret);
}
