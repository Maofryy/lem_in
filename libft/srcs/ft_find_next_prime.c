/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:26:26 by mbenhass          #+#    #+#             */
/*   Updated: 2019/01/29 14:27:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 0 || nb == 1)
		return (0);
	if (nb == 2147483629 || nb == 2147483647)
		return (1);
	while (i * i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	while (ft_is_prime(nb + i) == 0)
		i++;
	return (nb + i);
}
