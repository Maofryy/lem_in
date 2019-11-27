/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:29:49 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:28:31 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pad_fieldprecision(t_flags *fl, t_intstuff *vars)
{
	if (fl->fl_pr > 0 && fl->buf.size < fl->fl_pr)
	{
		buf_pad(&(fl->buf), '0', fl->fl_pr, 0);
		if (!(fl->buf.str))
			exit(1);
	}
	vars->can_expand = fl->fl_pr < 0
		&& fl->fl_zero == 1 && !(fl->fl_minus == 1);
	if (fl->fl_fw > 0 && vars->can_expand)
	{
		vars->offset = 0;
		if ((fl->fl_cv == 4)
			&& (vars->neg || fl->fl_plus == 1 || fl->fl_space == 1))
			vars->offset += 1;
		else if (fl->fl_sharp == 1 && fl->fl_cv == 5
			&& (!(vars->is_zero) || fl->fl_pr == 0))
			vars->offset += 1;
		else if (fl->fl_sharp == 1 && (fl->fl_cv == 7 || fl->fl_cv == 8)
			&& !(vars->is_zero))
			vars->offset += 2;
		buf_pad(&(fl->buf), '0', fl->fl_fw - vars->offset, 0);
		if (!(fl->buf.str))
			exit(1);
	}
}

static void	prepend_stuff(t_flags *fl, t_intstuff *vars)
{
	pad_fieldprecision(fl, vars);
	if (fl->fl_cv == 4)
	{
		if (vars->neg)
			buf_prepend("-", &(fl->buf));
		else if (fl->fl_plus == 1)
			buf_prepend("+", &(fl->buf));
		else if (fl->fl_space == 1)
			buf_prepend(" ", &(fl->buf));
		if (!(fl->buf.str))
			exit(1);
	}
	if (fl->fl_sharp == 1)
	{
		if (fl->fl_cv == 5 && ((fl->buf.str)[0] != '0' || fl->fl_pr == 0))
			buf_prepend("0", &(fl->buf));
		else if ((fl->fl_cv == 7 || fl->fl_cv == 8) && !(vars->is_zero))
			buf_prepend("0X", &(fl->buf));
		else if ((fl->fl_cv == 11) && !(vars->is_zero))
			buf_prepend("0b", &(fl->buf));
		if (!(fl->buf.str))
			exit(1);
	}
}

void		convert_int(t_flags *fl, va_list *ap)
{
	t_intstuff	vars;

	vars.neg = intval_to_buf(fl, ap);
	if (!(fl->buf.str))
		exit(1);
	fl->buf.size = ft_strlen(fl->buf.str);
	vars.is_zero = fl->buf.size == 0
		|| (fl->buf.size == 1 && (fl->buf.str)[0] == '0');
	prepend_stuff(fl, &vars);
	if (fl->fl_cv == 7)
		fl->buf.str = ft_strtolower(fl->buf.str);
	if (fl->fl_fw > 0
		&& fl->buf.size < fl->fl_fw && !(vars.can_expand))
		buf_pad(&(fl->buf), ' ', fl->fl_fw, fl->fl_minus == 1);
}
