#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 15:45:37 by hdelanoe          #+#    #+#              #
#    Updated: 2017/05/15 18:11:19 by hdelanoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC =	ft_memccpy.c \
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memdel.c	\
		ft_memmove.c \
		ft_memset.c	\
		ft_memalloc.c \
		ft_bzero.c \
		ft_strisalpha.c \
		ft_strisnum.c \
		ft_strisalnum.c \
		ft_strisprint.c \
		ft_strnew.c \
		ft_strequ.c	\
		ft_striter.c \
		ft_strnstr.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_strcat.c	\
		ft_strlcat.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strclr.c \
		ft_strmap.c	\
		ft_strtrim.c \
		ft_strcmp.c \
		ft_strmapi.c \
		ft_strcpy.c	\
		ft_strncpy.c \
		ft_strncat.c \
		ft_strdel.c	\
		ft_strncmp.c \
		ft_strdup.c	\
		ft_strnequ.c \
		ft_strrev.c \
		ft_striteri.c \
		ft_strchr.c	\
		ft_strlen.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putnbr.c	\
		ft_putnbr_fd.c \
		ft_putstr.c	\
		ft_putstr_fd.c \
		ft_putchar.c \
		ft_putchar_fd.c	\
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstaddend.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c \
		ft_lstcat.c \
		ft_lstjoin.c \
		ft_lstfind.c \
		ft_lstrev.c \
		ft_lstclr.c \

OBJ	=	$(SRC:.c=.o)


CC	= gcc

FLAGS = -Wall -Werror -Wextra


# compile libft.a
all	: $(NAME)
	
$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) 	: $(SRC) 
	$(CC) $(FLAGS) -c $(SRC)

# supprime les objets
clean	: 
	rm -rf $(OBJ)

# supprime les objets et la lib
fclean	: clean
	rm -rf $(NAME)

# fait place net et compile a nouveau
re		: fclean all
