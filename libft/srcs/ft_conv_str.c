/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:28:05 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 14:04:27 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	buf_size(t_buf *buf, wchar_t *str)
{
	buf->size = 0;
	while (*str != L'\0')
	{
		buf->size += wide_bytes_count(*str);
		str++;
	}
}

static int	fix_wstr_precision(t_flags *fl, wchar_t *str)
{
	int	size;

	size = 0;
	while (*str != L'\0')
	{
		size += wide_bytes_count(*str);
		if (size > fl->fl_pr)
			return (size - wide_bytes_count(*str));
		str++;
	}
	return (fl->fl_pr);
}

void		convert_str(t_flags *fl, va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL || (fl->fl_sc != 3))
	{
		if (!(fl->buf.str = ft_strdup(!str ? "(null)" : str)))
			exit(1);
		fl->buf.size = ft_strlen(fl->buf.str);
	}
	else
	{
		buf_size(&(fl->buf), (wchar_t *)str);
		if (!(fl->buf.str = (char *)malloc(fl->buf.size)))
			exit(1);
		convert_wide_str(fl->buf.str, (wchar_t *)str);
		if (fl->fl_pr > 0)
			fl->fl_pr = fix_wstr_precision(fl, (wchar_t *)str);
	}
	if (fl->fl_pr >= 0 && fl->buf.size > fl->fl_pr)
		fl->buf.size = fl->fl_pr;
	if (fl->fl_fw > 0 && fl->buf.size < fl->fl_fw)
		buf_pad(&(fl->buf), pad_byte(fl), fl->fl_fw
				, (fl->fl_minus == 1));
}

void		convert_char(t_flags *fl, va_list *ap)
{
	wint_t	c;

	if (!(fl->buf.str = (char *)malloc((fl->fl_sc == 3) ? 4 : 1)))
		exit(1);
	if ((fl->fl_sc != 3))
	{
		(fl->buf.str)[0] = (char)va_arg(*ap, int);
		fl->buf.size = 1;
	}
	else
	{
		c = va_arg(*ap, wint_t);
		fl->buf.size = convert_wide_c(fl->buf.str, c);
		if (!wide_valid(c))
		{
			fl->buf.size = -1;
			return ;
		}
	}
	if (fl->fl_fw > 0 && fl->buf.size < fl->fl_fw)
		buf_pad(&(fl->buf), pad_byte(fl), fl->fl_fw
				, (fl->fl_minus == 1));
}
