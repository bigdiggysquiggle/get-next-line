/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:46:27 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/30 19:54:07 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;

	if ((t = (t_list *)malloc(sizeof(t_list))))
	{
		if (content)
		{
			t->content = malloc(content_size);
			t->content = ft_memcpy(t->content, content, content_size);
			t->content_size = content_size;
		}
		else
		{
			t->content = NULL;
			t->content_size = 0;
		}
		t->next = NULL;
		return (t);
	}
	return (NULL);
}
