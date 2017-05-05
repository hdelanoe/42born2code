#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 15:45:37 by hdelanoe          #+#    #+#              #
#    Updated: 2017/04/10 17:04:09 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC	= srcs/ft_putchar.c\
	srcs/ft_putstr.c\
	srcs/ft_strcmp.c\
	srcs/ft_strlen.c\
	srcs/ft_swap.c\

OBJ	= ft_putchar.o\
	ft_putstr.o\
	ft_strcmp.o\
	ft_strlen.o\
	ft_swap.o\

HEAD	= -I includes/\

CC	= gcc

FLAGS = -Wall -Werror -Wextra


# compile libft.a
all	: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) 	: $(SRC)
	$(CC) $(FLAGS) -c $(SRC) $(HEAD)

# supprime les objets
clean	: 
	rm -rf $(OBJ)

# supprime les objets et la lib
fclean	: clean
	rm -rf $(NAME)

# fait place net et compile a nouveau
re		: fclean all
