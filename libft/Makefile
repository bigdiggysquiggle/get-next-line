# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2018/11/11 13:31:59 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./src/*.c

I = ./include

O = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I $(I) $(SRCS) -c
	ar rcs $(NAME) $(O)
	ranlib $(NAME)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

reclean: re
	rm -rf $(O)
