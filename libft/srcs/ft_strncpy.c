/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 04:56:43 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/07 16:58:49 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	str = (char *)src;
	while (str[i] && k < n)
	{
		dst[i] = str[i];
		i++;
		k++;
	}
	while (k < n)
	{
		dst[i++] = '\0';
		k++;
	}
	return (dst);
}
