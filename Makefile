# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <ngrasset@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 18:16:02 by ngrasset          #+#    #+#              #
#    Updated: 2018/05/02 16:58:18 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_OTOOL = ft_otool
NAME_NM = ft_nm

C_DIR = src
C_COMMON = src/file.c src/magic.c src/debug_header.c \
			src/fat.c src/archives.c src/offset.c src/fat_64.c
C_OTOOL = $(C_COMMON) src/main_otool.c src/errors_otool.c src/otool_dump.c
C_NM = $(C_COMMON) src/main_nm.c src/browse_nlist.c src/nm_types.c src/nm_lists.c \
	   src/errors_nm.c

O_DIR =	.tmp/obj
O_OTOOL_FILES = $(C_OTOOL:$(C_DIR)%.c=$(O_DIR)%.o)
O_NM_FILES = $(C_NM:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I ./includes -I ./libft/includes  -I ./ft_printf/includes
LIB = -L ./libft -l ft -L ./ft_printf -l ftprintf

CC = clang

all: $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): $(O_NM_FILES)
	make -C libft
	make -C ft_printf
	$(CC) $(FLAGS) $^ $(INCLUDES) $(LIB) -o $@

$(NAME_OTOOL): $(O_OTOOL_FILES)
	make -C libft
	make -C ft_printf
	$(CC) $(FLAGS) $^ $(INCLUDES) $(LIB) -o $@

$(O_NM_FILES): includes/ft_nm.h

$(O_OTOOL_FILES): includes/ft_nm.h

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
	@rm -f $(NAME_OTOOL) || true
	@rm -f $(NAME_NM) || true
	@rm -Rf .tmp/

re: fclean all

.PHONY: clean all fclean re
