# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 13:02:27 by amoroziu          #+#    #+#              #
#    Updated: 2018/11/11 11:23:50 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = algorithm.c arrdel.c arrdup.c arrlen.c arrprint.c check.c expend.c\
fill_map.c main.c read_file.c sqrt_ceil.c

LIBFILES =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c\
			ft_memccpy.c \
			ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_putchar.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c

LIB = libft.a

FLAGC = -Wall -Wextra -Werror

.PHONY: all clean fclean re

OBJ = $(LIBFILES:%.c=%.o)
OBJFILLIT = $(SRC:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(LIB) $(OBJFILLIT)
	@$(CC) $(FLAGC) $(OBJFILLIT) $(LIB) -o $(NAME)

$(OBJFILLIT): $(SRC)
	@$(CC) $(FLAGC) -c $(SRC)

$(LIB):
	@$(CC) $(FLAGC) -c $(LIBFILES)
	@ar rc $(LIB) $(OBJ)

clean:
	@rm -f $(OBJ) $(OBJFILLIT)

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all