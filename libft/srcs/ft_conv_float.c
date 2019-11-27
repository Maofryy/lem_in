/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:29:04 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 16:22:32 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	double_precision(t_flags *fl)
{
	char	*tmp;

	if (fl->fl_pr < 0)
		fl->fl_pr = 6;
	if (fl->fl_pr != 0)
	{
		if (!(tmp = (char *)malloc(fl->buf.size + fl->fl_pr + 1)))
			return (0);
		ft_memcpy(tmp, fl->buf.str, fl->buf.size);
		free(fl->buf.str);
		tmp[fl->buf.size] = '.';
		fl->buf.str = tmp;
		fl->buf.size += fl->fl_pr + 1;
	}
	else if (fl->fl_sharp == 1)
	{
		if (!(tmp = (char *)malloc(fl->buf.size + fl->fl_pr + 1)))
			return (0);
		ft_memcpy(tmp, fl->buf.str, fl->buf.size);
		free(fl->buf.str);
		tmp[fl->buf.size] = '.';
		fl->buf.str = tmp;
		fl->buf.size++;
	}
	return (1);
}

static void	prepend_stuff(t_flags *fl, t_intstuff *vars)
{
	if (vars->neg)
		buf_prepend("-", &(fl->buf));
	else if (fl->fl_plus == 1)
		buf_prepend("+", &(fl->buf));
	else if (fl->fl_space == 1)
		buf_prepend(" ", &(fl->buf));
	if (!(fl->buf.str))
		exit(1);
	if (fl->fl_fw > fl->buf.size)
	{
		if (fl->fl_zero == 1 && fl->fl_minus != 1)
			buf_pad(&(fl->buf), '0', fl->fl_fw, 0);
		else
			buf_pad(&(fl->buf), ' ', fl->fl_fw, fl->fl_minus == 1);
	}
	if (!(fl->buf.str))
		exit(1);
}

static void	pass_to_next_int(t_flags *fl)
{
	long long		n;
	unsigned int	n_len;
	char			*n_str;
	unsigned int	i;

	n_len = 0;
	while (fl->buf.str[n_len] != '.')
		n_len++;
	n = ft_atoi(fl->buf.str);
	n_str = ft_lltoa(n + 1);
	i = -1;
	if (n_len == ft_strlen(n_str))
	{
		while (++i < n_len)
			fl->buf.str[i] = n_str[i];
	}
	else
	{
		while (++i < n_len)
			fl->buf.str[i] = '0';
		buf_pad(&(fl->buf), '1', fl->buf.size + 1, 0);
	}
}

static void	convert_double2(t_flags *fl, long double val)
{
	int			i;
	long double	value;

	value = val;
	value -= (long long)value;
	if (value < 0)
		value = -value;
	value *= ft_tenpow(fl->fl_pr + 1);
	if ((long long)value % 10 >= 5)
		value += 10;
	i = fl->buf.size;
	while (i > (fl->buf.size - fl->fl_pr))
	{
		value /= 10.0;
		(fl->buf.str)[i - 1] = (((long long)value % 10) + '0');
		i--;
	}
	if ((long long)value == 10)
		pass_to_next_int(fl);
}

void		convert_double(t_flags *fl, va_list *ap)
{
	long double	value;
	t_intstuff	vars;

	if (fl->fl_sc == 5)
		value = va_arg(*ap, long double);
	else
		value = va_arg(*ap, double);
	vars.neg = (value < 0) ? 1 : 0;
	value = (value < 0) ? -value : value;
	vars.is_zero = fl->buf.size == 0
		|| (fl->buf.size == 1 && (fl->buf.str)[0] == '0');
	if (((value - (long long)value) * 10 >= 5) && fl->fl_pr == 0)
		value++;
	if (!(fl->buf.str = ft_lltoa((long long)value)))
		exit(1);
	fl->buf.size = ft_strlen(fl->buf.str);
	if (!double_precision(fl))
		exit(1);
	convert_double2(fl, value);
	prepend_stuff(fl, &vars);
}
