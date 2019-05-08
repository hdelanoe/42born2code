# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 21:06:59 by hdelanoe          #+#    #+#              #
#    Updated: 2018/04/08 21:22:33 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= eval_expr

SRCS	=	\
			Fixed.class.cpp \
			main.cpp \

OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

CG		= \033[92m
CY		= \033[93m
CE		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[K$(CY)[EVAL_EXPR] :$(CE) $(CG)Compiling... $(CE)";
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[K$(CY)[EVAL_EXPR] :$(CE) $(CG)EVAL_EXPR Compiled!$(CE)";

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[EVAL_EXPR] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:

	@$(RM) $(OBJS)
	@echo "\033[K$(CY)[EVAL_EXPR] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean

	@$(RM) $(NAME)
	@echo "\033[K$(CY)[EVAL_EXPR] :$(CE) $(CG)Cleaning binary $(CE)";

re: fclean all

.PHONY: all, clean, fclean, re

