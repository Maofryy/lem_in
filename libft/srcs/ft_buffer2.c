/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:27:14 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 12:27:18 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	pad_byte(t_flags *fl)
{
	if (fl->fl_minus == 1)
		return (' ');
	if (fl->fl_zero == 1)
		return ('0');
	return (' ');
}

void	buf_pad(t_buf *buf, char pad, int width, int right_pad)
{
	char	*tmp;

	if (buf->size >= width)
		return ;
	if (!(tmp = (char *)malloc(width)))
		exit(1);
	if (!right_pad)
	{
		ft_memset(tmp, pad, width - buf->size);
		ft_memcpy(tmp + (width - buf->size), buf->str, buf->size);
	}
	else
	{
		ft_memcpy(tmp, buf->str, buf->size);
		ft_memset(tmp + buf->size, ' ', width - buf->size);
	}
	free(buf->str);
	buf->str = tmp;
	buf->size = width;
}

void	buf_prepend(char *s1, t_buf *buf)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1, buf->str)))
		exit(1);
	free(buf->str);
	buf->str = tmp;
	buf->size += ft_strlen(s1);
}
