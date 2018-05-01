# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 18:16:02 by ngrasset          #+#    #+#              #
#    Updated: 2018/04/28 14:51:22 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_otool

C_DIR = src
C_FILES = src/main_otool.c src/errors.c src/file.c src/magic.c src/debug_header.c \
			src/fat.c src/archives.c

O_DIR =	.tmp/obj
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I ./includes -I ./libft/includes  -I ./ft_printf/includes
LIB = -L ./libft -l ft -L ./ft_printf -l ftprintf

CC = clang

all: $(NAME)

$(NAME): $(O_FILES)
	make -C libft
	make -C ft_printf
	$(CC) $(FLAGS) $^ $(INCLUDES) $(LIB) -o $@

$(O_FILES): includes/ft_nm.h

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(O_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	make clean -C libft
	make clean -C ft_printf
	@rm -Rf $(O_DIR)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	@rm $(NAME) || true
	@rm -Rf .tmp/

debug:
	make -C libft
	$(CC) $(FLAGS) -g $(C_FILES) $(INCLUDES) $(LIB) -o $(NAME)_debug

re: fclean all

.PHONY: clean all fclean re
