/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:48 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:17:25 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_tenpow(int pow)
{
	long double	res;

	res = 1.0;
	while (pow--)
		res *= 10.0;
	return (res);
}

static int	is_c_conv(char c, t_flags *f)
{
	char *s;

	if (c == 'i')
	{
		f->fl_cv = 4;
		return (1);
	}
	s = ft_strchr(STR_CONV, c);
	if (s == NULL || *s == 0)
		return (0);
	else
		f->fl_cv = s - STR_CONV + 1;
	return (1);
}

void		pf_convert(t_flags *fl, va_list *ap)
{
	if (fl->fl_cv_char == 'S' || fl->fl_cv_char == 'C'
			|| fl->fl_cv_char == 'D' || fl->fl_cv_char == 'O'
			|| fl->fl_cv_char == 'U')
	{
		fl->fl_cv_char = ft_tolower(fl->fl_cv_char);
		is_c_conv(fl->fl_cv_char, fl);
		fl->fl_sc = 3;
	}
	if (fl->fl_cv == 2)
		convert_str(fl, ap);
	else if (fl->fl_cv == 1)
		convert_char(fl, ap);
	else if (fl->fl_cv == 4
			|| fl->fl_cv == 5 || fl->fl_cv == 6
			|| fl->fl_cv == 7 || fl->fl_cv == 8
			|| fl->fl_cv == 11)
		convert_int(fl, ap);
	else if (fl->fl_cv == 9 || fl->fl_cv == 10)
		convert_double(fl, ap);
	else if (fl->fl_cv == 3)
		convert_pointer(fl, ap);
	else if (fl->fl_cv_char != 0)
		convert_other(fl);
}
