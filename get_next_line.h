/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:09:18 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/20 19:32:57 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

# define BUFF_SIZE 42

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(const int fd, char **line);

#endif
