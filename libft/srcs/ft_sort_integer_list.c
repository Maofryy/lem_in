/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:23:58 by mbenhass          #+#    #+#             */
/*   Updated: 2019/01/29 14:37:43 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_list(int *tab, int size)
{
	int i;
	int max;
	int tmp;

	i = 0;
	max = 0;
	if (size != 1)
	{
		while (i < size)
		{
			if (tab[i] > tab[max])
			{
				max = i;
			}
			i++;
		}
		tmp = tab[max];
		tab[max] = tab[size - 1];
		tab[size - 1] = tmp;
		ft_sort_integer_list(tab, size - 1);
	}
	return ;
}
