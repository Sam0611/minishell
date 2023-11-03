# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/06/20 20:05:03 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJ	:= build
DIR_BIN	:= bin

NAME	:= $(DIR_BIN)/libft_string.a

SRC		:= memcpy.c strchr.c strlcat.c strncmp.c substr.c \
			bzero.c memmove.c strdup.c strlcpy.c strnstr.c  \
			memchr.c memset.c striteri.c strlen.c strrchr.c \
			memcmp.c split.c strjoin.c strmapi.c strtrim.c \
			strcat.c strcmp.c
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
