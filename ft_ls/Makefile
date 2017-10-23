# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 12:06:00 by hdelanoe          #+#    #+#              #
#    Updated: 2017/10/19 13:28:53 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC =	main.c \
		ft_init.c \
		ft_flag.c \
		ft_list.c \
		ft_ls.c \
		ft_sort.c \
		ft_mode.c \
		ft_print.c \
		ft_help.c \
		ft_free.c \
		ft_tools.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror  -O2 -g
RM = rm -rf
INC = -I includes/
FT = -I libft/
LFT = -C libft/
PTF = -C ft_printf/
CG = \033[92m
CY =  \033[93m
CE = \033[0m

all: $(NAME)
$(NAME): $(OBJ)
	@echo "\033[K$(CY)[LS] :$(CE) $(CG)Creating Library ...$(CE)";
	@make $(LFT) all
	@make $(PTF) all
	@$(CC) -o $(NAME)  $(OBJ) $(LIBFT) $(PRINTF)
	@echo "\033[K$(CY)[LS] :$(CE) $(CG)LS Compiled!$(CE)";
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[LS] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
clean:
	@$(RM) $(OBJ)
	@make $(LFT) clean
	@make $(PTF) clean
	@echo "\033[K$(CY)[LS] :$(CE) $(CG)Cleaning Object files $(CE)";
fclean: clean
	@$(RM) $(NAME)
	@make $(LFT) fclean
	@make $(PTF) fclean
re: fclean all
