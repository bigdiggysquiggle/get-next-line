/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:44:40 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/30 19:56:21 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *d1337;
	t_list *next;

	d1337 = *alst;
	while (d1337)
	{
		next = d1337->next;
		del(d1337->content, d1337->content_size);
		free(d1337);
		d1337 = next;
	}
	*alst = NULL;
}
