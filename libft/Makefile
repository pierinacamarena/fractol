# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 21:44:22 by pcamaren          #+#    #+#              #
#    Updated: 2019/12/01 00:27:05 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libft.a

SOURCE =			src/ft_atoi.c 			\
						src/ft_bzero.c 		\
						src/ft_calloc.c 		\
						src/ft_intsize.c		\
						src/ft_isalnum.c		\
						src/ft_isalpha.c		\
						src/ft_isascii.c		\
						src/ft_isdigit.c		\
						src/ft_isprint.c		\
						src/ft_itoa.c			\
						src/ft_memccpy.c		\
						src/ft_memchr.c		\
						src/ft_memcmp.c		\
						src/ft_memcpy.c		\
						src/ft_memmove.c		\
						src/ft_memset.c		\
						src/ft_putchar_fd.c	\
						src/ft_putendl_fd.c	\
						src/ft_putnbr_fd.c	\
						src/ft_putstr_fd.c	\
						src/ft_split.c		\
						src/ft_strcat.c		\
						src/ft_strchr.c		\
						src/ft_strdup.c		\
						src/ft_strjoin.c		\
						src/ft_strlcat.c		\
						src/ft_strlcpy.c		\
						src/ft_strlen.c		\
						src/ft_strmapi.c		\
						src/ft_strcmp.c			\
						src/ft_strncmp.c		\
						src/ft_strnew.c		\
						src/ft_strnstr.c		\
						src/ft_strrchr.c		\
						src/ft_strtrim.c		\
						src/ft_substr.c		\
						src/ft_tolower.c		\
						src/ft_toupper.c		\
						src/ft_wordcount.c	\

INC             = -I includes/

OFILES = $(SOURCE:.c=.o)

CC = 				gcc
CFLAGS =			-Wall -Wextra -Werror -g
AR =				ar
ARFLAGS = 			-r -c

all:				$(NAME)

$(NAME): $(OFILES)
		$(AR) $(ARFLAGS) $(NAME) $^
		ranlib $(NAME)

#the % is a symbol that can be used the represent a given name and have it
#match exactly in the other one,kind of like *. So here it is saying for all
#.o dependecies of a %(given name) get the .c dependency with %(the same name)
#the $(CC) tells it to compile, then come the flags, then the include file
#then the first dependency and after the @matches the entire name e.g main.o fully
%.o: %.c libft.h
		$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
		rm -f $(OFILES)

fclean:					clean
		rm -f $(NAME)

re:								fclean all
