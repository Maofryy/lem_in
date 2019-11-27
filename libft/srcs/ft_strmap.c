/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:36:41 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/13 17:42:29 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;
	char	*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (str[i])
		i++;
	if ((ret = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = (*f)(str[i]);
		i++;
	}
	return (ret);
}
