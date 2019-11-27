/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:16:23 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/12 10:42:28 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*strref;

	i = 0;
	str = (char *)s;
	strref = str;
	if (c == 0)
		return (&str[ft_strlen(str)]);
	while ((str = ft_strchr(strref + i, c)) != NULL && (c != 0))
		i = str - strref + 1;
	if (i == 0)
		return (NULL);
	return (strref + i - 1);
}
