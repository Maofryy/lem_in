/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:28:11 by mbenhass          #+#    #+#             */
/*   Updated: 2019/08/29 14:59:45 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_power(long int nb, int power)
{
	if (power < 0)
		return (1 / ft_power(nb, - power));
	else if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}
#include <stdio.h>
double		ft_dpower(double nb, int power)
{
	if (power < 0)
		return (1 / ft_dpower(nb, -power));
	else if (power == 0)
		return (1);
	else
		return (nb * ft_dpower(nb, power - 1));
}
