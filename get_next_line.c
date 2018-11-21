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

void	list_remove(t_list **begin_list, int fd)
{
	t_list	*last;
	t_list	*curr;
	t_list	*temp;

	last = NULL;
	curr = *begin_list;
	temp = NULL;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
		{
			if (curr == *begin_list)
				*begin_list = curr->next;
			else
				last->next = curr->next;
			temp = curr;
			curr = curr->next;
			free(temp);
		}
		else
		{
			last = curr;
			curr = curr->next;
		}
	}
}

int				a_or_b(size_t a, size_t b, size_t len)
{
	if (b <= len)
		return ((int)b);
	else
		return ((int)a);
}

char			*list_advance(t_list **list, char *buf, int a, int fd)
{
	char		*line;
	char		*temp;
	size_t		len;

	line = NULL;
	if (ft_strlen(buf))
	{
		len = ft_strlen(buf);
		line = ft_strsub(buf, 0, a);
		a = (buf[a] != '\0') ? (a + 1) : a;
		temp = ft_strsub(buf, a, ft_strlen(buf + a));
		a = (int)ft_strlen((*list)->content);
		if (a != 0)
			free((*list)->content);
		(*list)->content = temp;
		if (!ft_strlen((*list)->content))
			list_remove(list, fd);
		return (line);
	}
	return (buf);
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
			a_or_b(a, b, ft_strlen(tmp->content)), fd);
	if (a == 0 && !ft_strlen(*line))
		return (0);
	return (1);
}
