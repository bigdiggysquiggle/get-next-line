/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:26:19 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/20 19:14:06 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(char **s, char **line, int fd, int r)
{
	char	*tmp;
	int		i;

	i = chr_index(s[fd], '\n');
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, r));
}
