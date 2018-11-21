/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:22:36 by dromansk          #+#    #+#             */
/*   Updated: 2018/10/23 15:01:11 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		p;

	a = c;
	p = 0;
	while (s[p])
		p++;
	if (a == '\0')
		return ((char *)(s + p));
	else
	{
		while (p != 0 && s[p] != a)
			p--;
		if (p == 0 && s[p] == a)
			return ((char *)s);
		else if (p != 0 && s[p] == a)
			return ((char *)(s + p));
	}
	return (NULL);
}
