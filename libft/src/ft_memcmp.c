/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:30:24 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/01 17:44:45 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *st1;
	const unsigned char *st2;

	st1 = s1;
	st2 = s2;
	if (n)
	{
		while (*st1 == *st2 && n-- > 1)
		{
			st1++;
			st2++;
		}
		return (*st1 - *st2);
	}
	else
		return (0);
}
