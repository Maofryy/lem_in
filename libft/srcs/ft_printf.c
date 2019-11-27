/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:23:26 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 17:06:42 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_buf	buf;
	int		ret;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	ret = read_format(&buf, format, &ap);
	va_end(ap);
	if (ret > 0)
		ret = write(1, buf.str, buf.pos);
	if (buf.str != NULL)
		free(buf.str);
	return (ret);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	t_buf	buf;
	int		ret;

	if (fd < 0 || format == NULL)
		return (-1);
	va_start(ap, format);
	ret = read_format(&buf, format, &ap);
	va_end(ap);
	if (ret > 0)
		ret = write(fd, buf.str, buf.pos);
	if (buf.str != NULL)
		free(buf.str);
	return (ret);
}

int			ft_asprintf(char **ret, const char *restrict format, ...)
{
	va_list	ap;
	t_buf	buf;
	int		n;

	if (ret == NULL || format == NULL)
		return (-1);
	va_start(ap, format);
	n = read_format(&buf, format, &ap);
	va_end(ap);
	if (n > 0)
	{
		if (!(*ret = (char *)malloc(buf.pos + 1)))
			exit(1);
		ft_memcpy(*ret, buf.str, buf.pos);
		(*ret)[buf.pos] = '\0';
	}
	if (buf.str != NULL)
		free(buf.str);
	return (n);
}

int			ft_sprintf(char *str, const char *restrict format, ...)
{
	va_list	ap;
	t_buf	buf;
	int		n;

	if (str == NULL || format == NULL)
		return (-1);
	va_start(ap, format);
	n = read_format(&buf, format, &ap);
	va_end(ap);
	if (n > 0)
	{
		ft_memcpy(str, buf.str, buf.pos);
		str[buf.pos] = '\0';
	}
	if (buf.str != NULL)
		free(buf.str);
	return (n);
}
