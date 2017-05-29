# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/05 04:28:05 by hdelanoe          #+#    #+#              #
#    Updated: 2017/05/28 17:25:04 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft/libft.a
HEADER = -I inc/

SRC = main.c \
	  ft_rgb.c \
	  ft_key.c \
	  ft_dend.c \
	  ft_glynn.c \
	  ft_image.c \
	  ft_mouse.c \
	  ft_mandel.c \
	  ft_julia.c \
	  ft_voodoo.c \
	  ft_burnin.c \

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra 
MLXFLAGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

#compile fdf
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(HEADER) $(MLXFLAGS)

$(OBJ) : $(SRC)
	make -C libft/ all
	$(CC) $(FLAGS) -c $(SRC)

# supprime les objets
clean :
	make -C libft/ clean
	$(RM) $(OBJ)

#supprime les objets et l'executable
fclean : clean
	make -C libft/ fclean
	$(RM) $(NAME)

# fait place net et compile a nouveau
re : fclean all
	make -C libft/ re

.PHONY : all clean fclean re
