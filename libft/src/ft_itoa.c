/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:03:00 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/01 15:06:17 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char *s;

	if ((s = (char *)malloc(sizeof(char) * 2)))
	{
		if (n == -2147483648)
			return (ft_strcpy(s, "-2147483648"));
		if (n < 0)
		{
			s[0] = '-';
			s[1] = '\0';
			return (ft_strjoin(s, ft_itoa(-n)));
		}
		else if (n >= 10)
			s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		else if (n < 10 && n >= 0)
		{
			s[0] = n + '0';
			s[1] = '\0';
		}
		return (s);
	}
	return (NULL);
}
