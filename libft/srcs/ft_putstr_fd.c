/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:29:28 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/16 16:54:29 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	char *str;

	if (s == NULL)
		return ;
	str = (char *)s;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
