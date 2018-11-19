/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:35:19 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/10 18:40:54 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	i;

	i = 0;
	if (s != NULL)
		if ((n = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (i < len)
				n[i++] = s[start++];
			n[i] = '\0';
			return (n);
		}
	return (NULL);
}
