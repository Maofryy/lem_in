/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:47:55 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/21 12:18:48 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_char(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static size_t	count_words(char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_char(str[i], c) && str[i])
			i++;
		if (!is_char(str[i], c) && str[i])
		{
			count++;
			while (!is_char(str[i], c) && str[i])
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char *str, int i, char c)
{
	size_t	count;

	count = 0;
	while (is_char(str[i], c) && str[i])
		i++;
	while (!is_char(str[i], c) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	tab = (char **)ft_memalloc(sizeof(char *) * (count_words(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (j < (int)count_words(str, c))
	{
		while (str[i] == c && str[i])
			i++;
		tab[j] = ft_strsub((const char *)&str[i], 0, word_len(str, i, c));
		if (tab[j] == NULL)
			return (NULL);
		i += word_len(str, i, c);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
