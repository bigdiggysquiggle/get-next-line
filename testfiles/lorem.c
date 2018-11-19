/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lorem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:56:40 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/19 14:58:17 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		main(int ac, char *av)
{
	char *s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus";
	if (ac == 2)
	{
		int i = atoi(av[1]);
		while (i--)
			ft_putstr(s);
	}
}
