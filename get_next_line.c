/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:10:26 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/19 20:16:50 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*sanity_check(t_list **list, int fd, char **line)
{
	t_list		*curr;

	if (list == NULL || line == NULL || fd < 0)
		return (NULL);
	if ((line != NULL) && *line == NULL)
		*line = ft_strnew(0);
	curr = *list;
	while (curr)
	{
		if ((int)curr->content_size == fd)
			return (curr);
		curr = curr->next;
	}
	curr = ft_lstnew("\0", fd);
	ft_lstadd(list, curr);
	return (*list);
}

int				a_or_b(size_t a, size_t b, size_t len)
{
	if (b <= len)
		return ((int)b);
	else
		return ((int)a);
}

char			*list_advance(t_list **list, char *buf, int a)
{
	char		*line;
	size_t		len;

	line = NULL;
	if (buf)
	{
		len = ft_strlen(buf);
		line = ft_strsub(buf, 0, a);
		if ((*list)->content)
			free((*list)->content);
		a = (buf[a] != '\0') ? (a + 1) : a;
		(*list)->content = ft_strsub(buf, a, len - a);
	}
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	int				a;
	int				b;
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	t_list			*tmp;

	tmp = sanity_check(&list, fd, line);
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 ||
			!(*line) || tmp->content == NULL)
		return (-1);
	b = chr_n_index(tmp->content, '\n', (int)ft_strlen(tmp->content));
	while ((a = read(fd, buf, BUFF_SIZE)))
	{
		buf[a] = '\0';
		tmp->content = ft_strjoin(tmp->content, buf);
		b = chr_n_index((char *)tmp->content, '\n',
				ft_strlen((char *)tmp->content));
		if (b > 0)
			break ;
	}
	*line = list_advance(&tmp, tmp->content,
			a_or_b(a, b, ft_strlen(tmp->content)));
	if (a == 0 && !ft_strlen(*line))
		return (0);
	return (1);
}
