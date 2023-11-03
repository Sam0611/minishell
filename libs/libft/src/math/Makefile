# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 18:20:07 by kjimenez          #+#    #+#              #
#    Updated: 2023/06/20 18:20:24 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ	:= build
DIR_BIN	:= bin

NAME	:= $(DIR_BIN)/libft_math.a

SRC		:= pow.c
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
