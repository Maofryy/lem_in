/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:29:27 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/07 15:31:21 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*cpy;
	char	*str;

	cpy = dst;
	str = (char *)src;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			cpy[i] = c;
			return (&cpy[i + 1]);
		}
		cpy[i] = str[i];
		i++;
	}
	return (NULL);
}
