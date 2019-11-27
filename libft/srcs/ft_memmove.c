/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:06:46 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/07 15:31:03 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*cpy;
	const char	*str;

	cpy = (char *)dst;
	str = (char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			cpy[i] = str[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			cpy[i] = str[i];
		}
	}
	return (dst);
}
