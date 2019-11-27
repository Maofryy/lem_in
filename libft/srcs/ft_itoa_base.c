/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <mbenhass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:10:43 by mbenhass          #+#    #+#             */
/*   Updated: 2019/10/10 19:32:45 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_BASE_char(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'A');
}

static char	ft_base_char(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

char		*ft_itoa_base(int n, int base)
{
	unsigned int	value;
	int				count;
	char			*str;

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_base_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_base_char(value));
	return (str);
}

char		*ft_itoa_BASE(int n, int base)
{
	unsigned int	value;
	int				count;
	char			*str;

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_BASE_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_BASE_char(value));
	return (str);
}

char		*ft_lltoa_base(long long n, int base)
{
	unsigned int	value;
	int				count;
	char			*str;

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_base_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_base_char(value));
	return (str);
}
