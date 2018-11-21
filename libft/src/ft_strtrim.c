/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:52:29 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/08 16:39:07 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrimlen(char const *str)
{
	int	i;

	i = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str)
	{
		str++;
		i++;
	}
	if ((*(str - 1) == ' ' || *(str - 1) == '\n' || *(str - 1) == '\t')
			&& i > 1)
	{
		str--;
		while (*str == ' ' || *str == '\n' || *str == '\t')
		{
			i--;
			str--;
		}
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*n;
	int		i;
	int		p;

	if (s == NULL)
		return (NULL);
	i = ft_strtrimlen(s);
	p = 0;
	n = (char *)malloc(sizeof(char) * i);
	if (n == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (i-- > 1)
		n[p++] = *(s++);
	n[p] = '\0';
	return (n);
}
