# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/02/19 14:16:08 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ	:= build
DIR_BIN	:= bin

NAME	:= $(DIR_BIN)/libft_list.a

SRC		:= lstnew.c lstsize.c lstclear.c lstadd_front.c \
			lstlast.c lstadd_back.c lstdelone.c lstiter.c \
			lstmap.c
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
