# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/03/13 20:45:19 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ	:= build
DIR_BIN	:= bin

NAME	:= $(DIR_BIN)/libft_ctype.a

SRC		:= isalpha.c isalnum.c isprint.c isascii.c \
			isdigit.c toupper.c tolower.c
OBJ		:= $(addprefix $(DIR_OBJ)/,$(SRC:c=o))

CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -I../../include
ARFLAGS	:= rcs

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(DIR_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

vpath %.c src
