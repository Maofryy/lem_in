/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:27:40 by mbenhass          #+#    #+#             */
/*   Updated: 2019/01/29 14:27:58 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((j == 0) && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}
		else if ((j != 0) && (str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += 32;
		}
		else if (str[i] < '0' || str[i] > 'z' || (str[i] < 'a' && str[i] > 'Z'))
		{
			j = -1;
		}
		j++;
		i++;
	}
	return (str);
}
