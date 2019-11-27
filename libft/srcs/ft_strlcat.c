/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 20:11:24 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 10:07:03 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s1;
	size_t	s2;

	i = 0;
	s1 = 0;
	s2 = 0;
	while (dst[i] != '\0')
		i++;
	while (src[s1] != '\0')
		s1++;
	if (size <= i)
		s1 += size;
	else
		s1 += i;
	while (src[s2] != '\0' && i + 1 < size)
		dst[i++] = src[s2++];
	dst[i] = '\0';
	return (s1);
}
