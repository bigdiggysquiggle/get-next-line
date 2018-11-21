/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:50:12 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/31 15:44:40 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*sr;
	char			*ds;
	size_t			i;

	sr = (char *)src;
	ds = (char *)dst;
	i = -1;
	while (++i < n)
	{
		ds[i] = sr[i];
		if ((unsigned char)sr[i] == (unsigned char)c)
			return ((char *)(dst + ++i));
	}
	return (NULL);
}
