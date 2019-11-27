/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:28:46 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 14:30:23 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	new_buf(t_buf *pbuf)
{
	pbuf->str = NULL;
	pbuf->size = 0;
	pbuf->pos = 0;
}

void		expand_buf(t_buf *pbuf)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(pbuf->size + BUFFER_SIZE)))
		exit(1);
	if (pbuf->str != NULL)
	{
		ft_memcpy(tmp, pbuf->str, pbuf->size);
		free(pbuf->str);
	}
	pbuf->str = tmp;
	pbuf->size += BUFFER_SIZE;
}

static void	buf_join(t_buf *pbuf, const char *str, int size)
{
	while (pbuf->pos + size > pbuf->size)
		expand_buf(pbuf);
	if (size > 0)
		ft_memcpy(pbuf->str + pbuf->pos, str, size);
	pbuf->pos += size;
}

int			read_format(t_buf *pbuf, const char *str, va_list *ap)
{
	const char	*start;
	t_flags		fl;

	new_buf(pbuf);
	while ((start = ft_strchr(str, '%')) != NULL)
	{
		if (start > str)
			buf_join(pbuf, str, (int)(start - str));
		start += flags_parse(&fl, start + 1) + 1;
		if (fl.fl_cv_char == 0)
			return (1);
		str = start + 1;
		new_buf(&(fl.buf));
		pf_convert(&fl, ap);
		if (fl.buf.size > 0)
			buf_join(pbuf, fl.buf.str, fl.buf.size);
		if (fl.buf.str != NULL)
			free(fl.buf.str);
		if (fl.buf.size < 0)
			return (-1);
	}
	if (*str != '\0')
		buf_join(pbuf, str, ft_strlen(str));
	return (1);
}
