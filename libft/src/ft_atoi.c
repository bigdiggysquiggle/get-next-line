/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:08:17 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/01 22:51:55 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long neg;
	long nb;

	nb = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	if (*str && '0' <= *str && *str <= '9')
	{
		nb = 0;
		while (*str && '0' <= *str && *str <= '9')
		{
			nb = (10 * nb) + (*str - '0');
			str++;
		}
	}
	return (nb * neg);
}
