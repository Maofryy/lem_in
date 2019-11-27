/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:21:15 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 15:01:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int		die(char **line)
// {
// 	if (!**line)
// 	{
// 		ft_strdel(line);
// 		return (0);
// 	}
// 	else
// 		return (1);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static char	str[4096][BUFF_SIZE + 1];
// 	char		*buf;
// 	char		*cur;
// 	int			ret;

// 	buf = str[fd];
// 	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
// 		return (-1);
// 	*line = ft_strnew(0);
// 	while (TRUE)
// 	{
// 		if ((cur = ft_strchr(buf, 10)))
// 		{
// 			*line = ft_strnjoinfree(*line, buf, cur - buf);
// 			ft_strncpy(buf, &buf[cur - buf + 1], BUFF_SIZE - (cur - buf));
// 			return (1);
// 		}
// 		*line = ft_strnjoinfree(*line, buf, BUFF_SIZE);
// 		ret = read(fd, str[fd], BUFF_SIZE);
// 		buf[ret] = '\0';
// 		if (!ret)
// 			return (die(line));
// 	}
// }

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
