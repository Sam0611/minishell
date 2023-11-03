# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/09/07 15:26:51 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_BIN		:= bin
DIR_OBJ		:= build

NAME		:= $(DIR_BIN)/minishell

SRC			:=  minishell.c signal_handler.c \
				lexer.c quotes.c token.c lexer_destroy.c \
				expander.c expand_part.c ft_getenv.c replace_word.c \
				parser.c parser_destroy.c syntax_checker.c redirections.c \
				exec.c open_files.c get_path.c print_error.c builtins.c \
				cd.c env.c echo.c pwd.c exit.c export.c unset.c
				
OBJ			:= $(addprefix $(DIR_OBJ)/,$(SRC:c=o))

LIBS_PATH	:= libs
LIBFT_PATH	:= $(LIBS_PATH)/libft

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -I$(LIBFT_PATH)/include -Iinclude -gdwarf-4
LDFLAGS		:= -L$(LIBFT_PATH)/bin -lft_stdio -lft_string -lft_list -lft_ctype -lft_stdlib

GIT			:= git

MKDIR		:= mkdir -p

INIT_SUB	:= $(shell $(GIT) submodule init)
UPDATE_SUB	:= $(shell $(GIT) submodule update)
BUILD_LIBFT	:= $(shell $(MAKE) -C $(LIBFT_PATH))

VSUPFLAG	=	--suppressions=vsupp
VFDFLAG		=	--track-fds=yes
VCHFLAG		=	--trace-children=yes
VLEAKFLAG	=	--leak-check=full --show-leak-kinds=all
VFLAGS		=	${VSUPFLAG} ${VFDFLAG} ${VCHFLAG} ${VLEAKFLAG}

all: $(NAME)

minishell: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -lreadline

$(DIR_OBJ)/%.o: %.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

val0:
	valgrind ${VSUPFLAG} ./${NAME}

val1:
	valgrind ${VFLAGS} ./${NAME}

valfd:
	valgrind ${VSUPFLAG} ${VFDFLAG} ./${NAME}

valch:
	valgrind ${VSUPFLAG} ${VCHFLAG} ./${NAME}

valeak:
	valgrind ${VSUPFLAG} ${VLEAKFLAG} ./${NAME}

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all minishell clean fclean re

vpath %.c src:src/lexer:src/parser:src/executor:src/builtins:src/expander
