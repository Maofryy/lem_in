/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:28:46 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 14:28:37 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_other(t_flags *fl)
{
	if (!(fl->buf.str = (char *)malloc(1)))
		exit(1);
	(fl->buf.str)[0] = fl->fl_cv_char;
	fl->buf.size = 1;
	if (fl->fl_fw > 0 && fl->buf.size < fl->fl_fw)
		buf_pad(&(fl->buf), pad_byte(fl), fl->fl_fw
			, (fl->fl_minus == 1));
}

void	convert_pointer(t_flags *fl, va_list *ap)
{
	intptr_t	value;

	value = va_arg(*ap, intptr_t);
	if (!value && fl->fl_pr == 0)
		fl->buf.str = ft_strnew(0);
	else
		fl->buf.str = ft_lltoa_base(value, 16);
	if (!(fl->buf.str))
		exit(1);
	fl->buf.size = ft_strlen(fl->buf.str);
	fl->buf.str = ft_strtolower(fl->buf.str);
	if (fl->fl_pr > 0 && fl->fl_pr > fl->buf.size)
		buf_pad(&(fl->buf), '0', fl->fl_pr, 0);
	if (fl->fl_zero == 1 && !(fl->fl_minus == 1) && fl->fl_fw > 2)
		buf_pad(&(fl->buf), '0', fl->fl_fw - 2, 0);
	buf_prepend("0x", &(fl->buf));
	if (!(fl->buf.str))
		exit(1);
	if (fl->fl_fw > 0 && fl->buf.size < fl->fl_fw
		&& (!(fl->fl_zero == 1) || fl->fl_minus == 1))
		buf_pad(&(fl->buf), pad_byte(fl), fl->fl_fw
			, fl->fl_minus == 1);
}
