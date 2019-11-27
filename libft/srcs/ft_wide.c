/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:27:47 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 12:27:55 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wide_bytes_count(wint_t c)
{
	if (c < (1 << 7))
		return (1);
	else if (c < (1 << 11))
		return (2);
	else if (c < (1 << 16))
		return (3);
	else if (c < (1 << 21))
		return (4);
	return (-1);
}

int	wide_valid(wint_t c)
{
	if (c >= (1 << 21))
		return (0);
	return (wide_bytes_count(c) <= MB_CUR_MAX);
}

int	convert_wide_c(char *dst, wint_t c)
{
	int	index;

	index = 0;
	if (c < (1 << 7))
		dst[index++] = c;
	else if (c < (1 << 11))
	{
		dst[index++] = (c >> 6) | 0xC0;
		dst[index++] = (c & 0x3F) | 0x80;
	}
	else if (c < (1 << 16))
	{
		dst[index++] = (c >> 12) | 0xE0;
		dst[index++] = ((c >> 6) & 0x3F) | 0x80;
		dst[index++] = (c & 0x3F) | 0x80;
	}
	else if (c < (1 << 21))
	{
		dst[index++] = (c >> 18) | 0xF0;
		dst[index++] = ((c >> 12) & 0x3F) | 0x80;
		dst[index++] = ((c >> 6) & 0x3F) | 0x80;
		dst[index++] = (c & 0x3F) | 0x80;
	}
	return (index);
}

int	convert_wide_str(char *dst, wchar_t *str)
{
	int	offset;

	offset = 0;
	while (*str != L'\0')
	{
		offset += convert_wide_c(&(dst[offset]), *str);
		if (!wide_valid(*str))
			return (0);
		str++;
	}
	return (1);
}
