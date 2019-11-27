/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:08:31 by mbenhass          #+#    #+#             */
/*   Updated: 2018/12/04 09:31:31 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static	char	*ft_retnull(void)
{
	char	*ret;

	ret = (char*)malloc(1);
	ret[0] = '\0';
	return (ret);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	str = (char *)s;
	k = ft_strlen(str) - 1;
	while (is_space(str[j]) && str[j])
		j++;
	if (j == k + 1)
		return (ft_retnull());
	while (is_space(str[k]))
		k--;
	if ((ret = (char*)malloc(sizeof(char) * (k - j + 2))) == NULL)
		return (NULL);
	while (str[j] && j <= k)
		ret[i++] = str[j++];
	ret[i] = '\0';
	return (ret);
}
