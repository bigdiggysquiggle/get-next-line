/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:25:47 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/26 15:46:57 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	l;

	i = (unsigned char *)s;
	l = (unsigned char)c;
	while (n--)
	{
		if (*i == l)
			return (i);
		i++;
	}
	return (NULL);
}
