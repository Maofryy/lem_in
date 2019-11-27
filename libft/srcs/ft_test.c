/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:53:23 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:17:54 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_format_flag(char **pstr, t_flags *fl)
{
	char	*s;
	int		*p;

	p = &fl->fl_sharp;
	s = ft_strchr(STR_FLAGS, **pstr);
	if (s == NULL || **pstr == 0)
		return (0);
	*(p + (int)(s - STR_FLAGS)) = 1;
	(*pstr)++;
	return (1);
}

int		is_precision_flag(char **pstr, t_flags *fl)
{
	if (**pstr == '.')
	{
		(*pstr)++;
		fl->fl_pr = ft_positive_atoi(pstr);
		return (1);
	}
	else
		return (0);
}

int		is_width_field(char **pstr, t_flags *fl)
{
	if (IS_NUM((int)**pstr))
	{
		fl->fl_fw = ft_positive_atoi(pstr);
		return (1);
	}
	else
		return (0);
}

int		is_conv_flag(char **pstr, t_flags *fl)
{
	if (*pstr[0] == 'h')
	{
		if ((*pstr)[1] == 'h')
			(fl->fl_sc < 6) ? fl->fl_sc = 1 : 0;
		else
			(fl->fl_sc < 6) ? fl->fl_sc = 2 : 0;
	}
	else if ((*pstr)[0] == 'l')
	{
		if ((*pstr)[1] == 'l')
			(fl->fl_sc < 6) ? fl->fl_sc = 4 : 0;
		else
			(fl->fl_sc < 6) ? fl->fl_sc = 3 : 0;
	}
	else if ((*pstr)[0] == 'L')
		(fl->fl_sc < 6) ? fl->fl_sc = 5 : 0;
	else if ((*pstr)[0] == 'z')
		fl->fl_sc = 6;
	else if ((*pstr)[0] == 'j')
		fl->fl_sc = 7;
	else
		return (0);
	(*pstr)++;
	pass_conv_flag(pstr, fl);
	return (1);
}

int		is_conv(char **pstr, t_flags *f)
{
	char *s;

	if (**pstr == 'i')
	{
		f->fl_cv = 4;
		return (1);
	}
	else if (**pstr == 'F')
	{
		f->fl_cv = 9;
	}
	s = ft_strchr(STR_CONV, **pstr);
	if (s == NULL || *s == 0)
		return (0);
	else
		f->fl_cv = s - STR_CONV + 1;
	return (1);
}
