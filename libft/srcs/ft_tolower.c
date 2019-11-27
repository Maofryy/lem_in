/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:43:04 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/13 16:43:54 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_strtolower(char *s)
{
	char	*str;
	int	i;

	i = -1;
	str = s;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
