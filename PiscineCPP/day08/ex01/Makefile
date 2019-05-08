# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 17:31:08 by hdelanoe          #+#    #+#              #
#    Updated: 2019/04/03 17:31:09 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= iter

SRCS	=	\
			iter.cpp \

OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

CG		= \033[92m
CY		= \033[93m
CE		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[K$(CY)[ITER] :$(CE) $(CG)Compiling... $(CE)";
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[K$(CY)[ITER] :$(CE) $(CG)ITER Compiled!$(CE)";

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[ITER] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:

	@$(RM) $(OBJS)
	@echo "\033[K$(CY)[ITER] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean

	@$(RM) $(NAME)
	@echo "\033[K$(CY)[ITER] :$(CE) $(CG)Cleaning binary $(CE)";

re: fclean all

.PHONY: all, clean, fclean, re
