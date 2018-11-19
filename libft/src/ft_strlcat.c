/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:29:46 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/31 17:25:24 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst[a] && a < dstsize)
		a++;
	while (src[b] && dstsize > (a + b + 1))
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a != dstsize)
		dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
