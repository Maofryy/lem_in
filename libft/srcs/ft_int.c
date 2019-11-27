/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:28:26 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:28:12 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_positive_atoi(char **pstr)
{
	int ret;

	ret = 0;
	while ((*pstr)[0] >= '0' && (*pstr)[0] <= '9')
	{
		ret *= 10;
		ret += ((*pstr)[0] - '0');
		(*pstr)++;
	}
	return (ret);
}

static unsigned long long	get_ullong(t_flags *fl, va_list *ap)
{
	if (fl->fl_sc == 4)
		return (va_arg(*ap, unsigned long long));
	else if (fl->fl_sc == 3)
		return (va_arg(*ap, unsigned long));
	else if (fl->fl_sc == 1)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else if (fl->fl_sc == 2)
		return ((unsigned short)va_arg(*ap, unsigned int));
	else if (fl->fl_sc == 7)
		return (va_arg(*ap, uintmax_t));
	else if (fl->fl_sc == 6)
		return (va_arg(*ap, size_t));
	else
		return (va_arg(*ap, unsigned int));
}

static long long			get_llong(t_flags *fl, va_list *ap)
{
	if (fl->fl_sc == 4)
		return (va_arg(*ap, long long));
	else if (fl->fl_sc == 3)
		return (va_arg(*ap, long));
	else if (fl->fl_sc == 1)
		return ((char)va_arg(*ap, int));
	else if (fl->fl_sc == 2)
		return ((short)va_arg(*ap, int));
	else if (fl->fl_sc == 7)
		return (va_arg(*ap, intmax_t));
	else if (fl->fl_sc == 6)
		return (va_arg(*ap, long));
	else
		return (va_arg(*ap, int));
}

static int					get_base(t_flags *fl)
{
	int base;

	base = 10;
	if (fl->fl_cv == 5)
		base = 8;
	else if (fl->fl_cv == 7 || fl->fl_cv == 8)
		base = 16;
	else if (fl->fl_cv == 11)
		base = 2;
	return (base);
}

int							intval_to_buf(t_flags *fl, va_list *ap)
{
	int					base;
	unsigned long long	value;

	base = get_base(fl);
	value = 0;
	if (fl->fl_cv == 5 || fl->fl_cv == 6 || fl->fl_cv == 7 || fl->fl_cv == 8 
		|| fl->fl_cv == 11)
		value = get_ullong(fl, ap);
	else
	{
		value = get_llong(fl, ap);
		if (value >> ((sizeof(long long) * 8) - 1))
		{
			fl->buf.str = ft_ulltoa(~value + 1);
			return (1);
		}
	}
	if (value == 0 && fl->fl_pr == 0)
		fl->buf.str = ft_strnew(0);
	else
		fl->buf.str = ft_ulltoa_majbase(value, base);
	return (0);
}
