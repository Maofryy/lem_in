/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:27:41 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/07 15:30:07 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cpy;
	char	*str;

	cpy = dst;
	str = (char *)src;
	i = 0;
	while (i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (dst);
}
