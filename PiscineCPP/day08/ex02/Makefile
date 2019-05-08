# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 18:24:29 by hdelanoe          #+#    #+#              #
#    Updated: 2019/04/04 13:12:58 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= array

SRCS	=	\
			main.cpp \

OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
FLAGS	=  -std=c++98 -Wall -Wextra -Werror
RM		= rm -rf

CG		= \033[92m
CY		= \033[93m
CE		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[K$(CY)[ARRAY] :$(CE) $(CG)Compiling... $(CE)";
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[K$(CY)[ARRAY] :$(CE) $(CG)ARRAY Compiled!$(CE)";

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[ARRAY] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:

	@$(RM) $(OBJS)
	@echo "\033[K$(CY)[ARRAY] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean

	@$(RM) $(NAME)
	@echo "\033[K$(CY)[ARRAY] :$(CE) $(CG)Cleaning binary $(CE)";

re: fclean all

.PHONY: all, clean, fclean, re


