# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 18:35:18 by hdelanoe          #+#    #+#              #
#    Updated: 2019/04/06 16:26:30 by tfontani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_gkrellm

SRC_PATH	:=	srcs
SRC			:=	$(shell find $(SRC_PATH) -name *.cpp)
			

OBJ_PATH	:=	.obj
OBJ			:=	$(subst srcs,$(OBJ_PATH),$(SRC:.cpp=.o))

CC		:= clang++
FLAGS	:= -MMD -isystem ~/.brew/include -Wall -Wextra -Werror -std=c++98 -g
LIBS	:= -lncurses -L ~/.brew/lib -lsfml-graphics -lsfml-window -lsfml-system
LDOPTS	:= -Wl,-rpath ~/.brew/lib
RM		= rm -rf

#CG		= \033[92m
#CY		= \033[93m
#CE		= \033[0m

all: $(NAME)

#@echo "\033[K$(CY)[MONITOR] :$(CE) $(CG)Compiling... $(CE)";
#@echo "\033[K$(CY)[MONITOR] :$(CE) $(CG)MONITOR Compiled!$(CE)";

$(NAME): $(SRC) $(OBJ_PATH) $(OBJ)
	$(CC) -o $(NAME) $(LIBS) $(LDOPTS) $(OBJ)

#@echo "\033[K$(CY)[MONITOR] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp 
	$(CC) -o $@ $(FLAGS) -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)
	mkdir $(OBJ_PATH)/Display
	mkdir $(OBJ_PATH)/Module

-include $(OBJ:.o=.d)

#@echo "\033[K$(CY)[MONITOR] :$(CE) $(CG)Cleaning Object files $(CE)";
clean:
	$(RM) $(OBJ_PATH)

#@echo "\033[K$(CY)[MONITOR] :$(CE) $(CG)Cleaning binary $(CE)";
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
