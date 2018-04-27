# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 14:54:05 by ngrasset          #+#    #+#              #
#    Updated: 2018/04/27 13:45:08 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a 

SRC = format_args_parser.c format_struct.c parse_format.c print_formated.c print_numbers.c print_strings.c print_chars.c print_binary.c print_hexa.c utils.c print_octal.c print_unsigned_digit.c chars.c intmaxs.c ints.c long_longs.c longs.c shorts.c print_xstringf.c print_dstringf.c print_strings_wide.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I../libft/includes -I./includes

CFLAGS = -Wall -Wextra -Werror

LIBS = -L../libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar -rc $(NAME) $^
	libtool -static -o $(NAME) $(NAME) $(LIBS) 2>&-

%.o: srcs/%.c
	gcc $(CFLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

main: $(NAME) 
	gcc $(INCLUDES) -Wall -L./ -lftprintf $^ srcs/main.c -o bin_ftprintf
