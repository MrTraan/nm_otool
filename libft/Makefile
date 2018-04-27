# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:41:14 by ngrasset          #+#    #+#              #
#    Updated: 2016/08/16 14:30:20 by ngrasset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_DIR = src
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIRS) -type f -follow -print | grep "\.c")

O_DIR = .tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

INCLUDES = -I includes/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rcs $@ $^

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(O_DIR) $(O_DIRS)
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<

clean:
	rm -Rf $(O_DIR)

fclean: clean
	@rm $(NAME) || true
	@rm -Rf .tmp/

re: fclean all

.PHONY: all clean flcean re
