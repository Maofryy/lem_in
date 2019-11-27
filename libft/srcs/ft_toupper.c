/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:41:13 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/13 17:36:32 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char		*ft_strtoupper(char *s)
{
	char	*str;
	int	i;

	i = -1;
	str = s;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}
