# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 12:06:00 by hdelanoe          #+#    #+#              #
#    Updated: 2017/11/21 13:18:49 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	minishell
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC =	\
	main.c \
	tools.c \
	env_flag.c \
	cd_builtin.c \
	env_builtin.c \
	echo_builtin.c \
	get_next_line.c \
	init_path.c \
	check_multi.c \
	lauch_command.c \
	setenv_builtin.c \
	print_computer.c \
	unsetenv_builtin.c \
		
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -O2
RM = rm -rf
INC = -I includes/
LFT = -C libft/
PTF = -C ft_printf/
CG = \033[92m
CY =  \033[93m
CE = \033[0m

all: $(NAME)
$(NAME): $(OBJ)
	@echo "\033[K$(CY)[MINISHELL] :$(CE) $(CG)Compiling ...$(CE)";
	@make $(LFT) all
	@make $(PTF) all
	@$(CC) -o $(NAME) -l termcap $(OBJ) $(LIBFT) $(PRINTF)
	@echo "\033[K$(CY)[MINISHELL] :$(CE) $(CG)MINISHELL Compiled!$(CE)";
	
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[MINISHELL] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
clean:
	@$(RM) $(OBJ)
	@make $(LFT) clean
	@make $(PTF) clean
	@echo "\033[K$(CY)[MINISHELL] :$(CE) $(CG)Cleaning Object files $(CE)";
fclean: clean
	@$(RM) $(NAME)
	@make $(LFT) fclean
	@make $(PTF) fclean
re: fclean all
