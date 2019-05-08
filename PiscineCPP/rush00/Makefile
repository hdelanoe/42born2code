# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 15:45:21 by hdelanoe          #+#    #+#              #
#    Updated: 2019/03/31 18:38:37 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro

SRC =		$(addprefix $(SRC_PATH)/,$(SRCS))
SRC_PATH =	./src
SRCS	=	\
			main.cpp \
			GameEngine/GameEngine.cpp \
			GameEngine/GameEngine_Update.cpp \
			AGameEntity.cpp \
			Player/Player.cpp \
			Player/AProjectile.cpp \
			Player/Laser.cpp \
			Enemy/AEnemy.cpp \
			Enemy/Drone.cpp \
			Enemy/Sentinel.cpp \
			Enemy/Satelite.cpp \
			Enemy/Missile.cpp \
			Light.cpp \
			Shield.cpp \

OBJ =		$(addprefix $(OBJ_PATH)/,$(OBJS))
OBJ_PATH =	./obj
OBJS	=	$(SRCS:.cpp=.o)

CC		= clang++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g
NCURSES = -lncurses
RM		= rm -rf

CG		= \033[92m
CY		= \033[93m
CE		= \033[0m

all: $(NAME)

$(NAME): $(SRC) $(OBJ_PATH) $(OBJ)
	@echo "\033[K$(CY)[FT_RETRO] :$(CE) $(CG)Compiling... $(CE)";
	@$(CC) $(NCURSES) -o $(NAME) $(OBJ)
	@echo "\033[K$(CY)[FT_RETRO] :$(CE) $(CG)FT_RETRO Compiled!$(CE)";

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp ./src/ft_retro.hpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[FT_RETRO] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)/Enemy
	@mkdir $(OBJ_PATH)/GameEngine
	@mkdir $(OBJ_PATH)/Player


clean:
	@$(RM) $(OBJ_PATH)
	@echo "\033[K$(CY)[FT_RETRO] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[K$(CY)[FT_RETRO] :$(CE) $(CG)Cleaning binary $(CE)";

re: fclean all

.PHONY: all, clean, fclean, re

