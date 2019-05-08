# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 12:07:32 by hdelanoe          #+#    #+#              #
#    Updated: 2018/04/13 12:07:33 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= identifier

SRCS	=	\
			main.cpp \
			Base.cpp \
			A.class.cpp \
			B.class.cpp \
			C.class.cpp \


OBJS	= $(SRCS:.cpp=.o)
CC		= clang++
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

CG		= \033[92m
CY		= \033[93m
CE		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[K$(CY)[IDENTIFIER] :$(CE) $(CG)Compiling... $(CE)";
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\033[K$(CY)[IDENTIFIER] :$(CE) $(CG)IDENTIFIER Compiled!$(CE)";

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[IDENTIFIER] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:

	@$(RM) $(OBJS)
	@echo "\033[K$(CY)[IDENTIFIER] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean

	@$(RM) $(NAME)
	@echo "\033[K$(CY)[IDENTIFIER] :$(CE) $(CG)Cleaning binary $(CE)";

re: fclean all

.PHONY: all, clean, fclean, re


