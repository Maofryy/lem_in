/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:27:03 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:11:09 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wctype.h>
# include <wchar.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define IS_NUM(x) (x >= '0' && x <= '9')
# define STR_CONV "cspdouxXfFb"
# define STR_FLAGS "#0+- "
# define BUFFER_SIZE 1024

typedef struct	s_buf
{
	char	*str;
	int		size;
	int		pos;
}				t_buf;

typedef struct	s_intstuff
{
	int			neg;
	int			is_zero;
	int			can_expand;
	int			offset;
}				t_intstuff;

typedef struct	s_flags
{
	int		fl_sharp;
	int		fl_zero;
	int		fl_plus;
	int		fl_minus;
	int		fl_space;
	int		fl_fw;
	int		fl_pr;
	int		fl_sc;
	int		fl_cv;
	int		fl_cv_sign;
	char	fl_cv_char;
	int		fl_err;
	t_buf	buf;

}				t_flags;

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				ft_asprintf(char **ret, const char *restrict format, ...);
int				ft_sprintf(char *str, const char *restrict format, ...);
int				read_format(t_buf *pbuf, const char *str, va_list *ap);
void			expand_buf(t_buf *pbuf);
/*
**		Flags parsing functions
*/

int				flags_parse(t_flags *fl, const char *str);
void			flags_init(t_flags *fl);
int				is_format_flag(char **pstr, t_flags *fl);
int				is_conv_flag(char **pstr, t_flags *fl);
int				is_precision_flag(char **pstr, t_flags *fl);
int				is_width_field(char **pstr, t_flags *fl);
int				is_conv(char **pstr, t_flags *fl);
void			pass_conv_flag(char **pstr, t_flags *fl);

void			convert_str(t_flags *fl, va_list *ap);
void			convert_char(t_flags *fl, va_list *ap);
void			pf_convert(t_flags *fl, va_list *ap);
char			pad_byte(t_flags *fl);
void			buf_pad(t_buf *buf, char pad, int width, int right_pad);
void			buf_prepend(char *s1, t_buf *buf);

int				wide_bytes_count(wint_t c);
int				wide_valid(wint_t c);

int				convert_wide_c(char *dst, wint_t c);
int				convert_wide_str(char *dst, wchar_t *str);
void			convert_other(t_flags *fl);
void			convert_pointer(t_flags *fl, va_list *ap);
void			convert_double(t_flags *fl, va_list *ap);
void			convert_int(t_flags *fl, va_list *ap);

int				intval_to_buf(t_flags *fl, va_list *ap);
int				ft_positive_atoi(char **str);
long double		ft_tenpow(int pow);

#endif
