/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:01:08 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 10:56:55 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int				ft_atol(const char *str)
{
	long long	i;
	long long	res;
	int		sign;
	char	*s;

	i = 0;
	res = 0;
	sign = 1;
	s = (char *)str;
	if (*s == '\0')
		return (0);
	while ((s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v')
	|| (s[i] == ' ') || (s[i] == '\f') || (s[i] == '\r'))
		i++;
	s[i] == '-' ? sign = -1 : 0;
	s[i] == '-' || s[i] == '+' ? i++ : 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}
