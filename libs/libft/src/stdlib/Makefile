# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/06/21 17:08:42 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ	:= build
DIR_BIN	:= bin

NAME	:= $(DIR_BIN)/libft_stdlib.a

SRC		:= atoi.c itoa.c calloc.c realloc.c
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
