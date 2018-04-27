# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:41:14 by ngrasset          #+#    #+#              #
#    Updated: 2016/03/03 21:56:56 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_memalloc.c		ft_memdel.c		ft_memset.c			ft_bzero.c\
		ft_memcpy.c			ft_memccpy.c	ft_memmove.c		ft_memchr.c\
		ft_memcmp.c			ft_strlen.c		ft_strdup.c			ft_strcpy.c\
		ft_strncpy.c		ft_strcat.c		ft_strncat.c		ft_strlcat.c\
		ft_strchr.c			ft_strrchr.c	ft_strstr.c			ft_strnstr.c\
		ft_strcmp.c			ft_strncmp.c	ft_atoi.c			ft_isalpha.c\
		ft_isdigit.c		ft_isalnum.c	ft_isascii.c		ft_isprint.c\
		ft_toupper.c		ft_tolower.c	ft_strnew.c			ft_strdel.c\
		ft_strclr.c			ft_striter.c	ft_striteri.c		ft_strmap.c\
		ft_strmapi.c		ft_strequ.c		ft_strnequ.c		ft_strsub.c\
		ft_strjoin.c		ft_strtrim.c	ft_strsplit.c		ft_count_words.c\
		ft_search_and_replace.c				ft_itoa.c			ft_putchar.c\
		ft_putstr.c			ft_putendl.c	ft_putnbr.c			ft_putchar_fd.c\
		ft_putstr_fd.c		ft_putendl_fd.c	ft_putnbr_fd.c		ft_lstnew.c\
		ft_lstdelone.c		ft_lstdel.c		ft_lstadd.c			ft_lstiter.c\
		ft_lstmap.c			ft_lstpush_back.c					ft_print_color.c\
		ft_getchar.c		ft_putstrtab.c	get_next_line.c		ft_lstpop.c\
		ft_delstrtab.c		ft_strjoin_delim.c					ft_str_isalpha.c\
		ft_realloc.c		ft_isspace.c	ft_putnchar.c		ft_itoa_base.c
NAME = libft.a
INCLUDES = -I includes/
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $@ $^

%.o: srcs/%.c
	$(CC) -c  $(INCLUDES) $(CFLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
