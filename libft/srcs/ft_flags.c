/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:48:59 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:19:30 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pass_conv_flag(char **pstr, t_flags *fl)
{
	if (fl->fl_sc == 1 || fl->fl_sc == 4)
		(*pstr)++;
}

void		flags_init(t_flags *fl)
{
	int	*p;

	p = &fl->fl_sharp;
	while (p <= &fl->fl_err)
	{
		*p = -1;
		p++;
	}
	fl->fl_cv = 0;
}

int			flags_parse(t_flags *fl, const char *str)
{
	const char	*start;

	start = str;
	flags_init(fl);
	while (is_format_flag((char **)&str, fl)
			|| is_conv_flag((char **)&str, fl)
			|| is_width_field((char **)&str, fl)
			|| is_precision_flag((char **)&str, fl))
		continue ;
	fl->fl_cv_char = *str;
	is_conv((char **)&str, fl);
	return (int)(str - start);
}
