/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:37:37 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/01 18:00:38 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t a;
	size_t b;

	a = 0;
	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	while (a < len && haystack[a])
	{
		b = 0;
		while (a + b < len && needle[b] && haystack[a + b] == needle[b])
			b++;
		if (!needle[b])
			return ((char *)haystack + a);
		a++;
	}
	return (NULL);
}
