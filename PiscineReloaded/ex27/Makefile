# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 15:08:25 by hdelanoe          #+#    #+#              #
#    Updated: 2017/04/10 17:18:31 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file

SRC		= display_file.c

OBJ		= display_file.o

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

#compile ft_display_file
all		: $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

$(OBJ)	: $(SRC)
		$(CC) $(FLAGS) -c $(SRC)

#supprime les objets
clean	:
		rm -rf $(OBJ)

#supprime les objets et l'executable
fclean	: clean
		rm -rf $(NAME)
