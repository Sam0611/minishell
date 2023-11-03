# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:53:31 by kjimenez          #+#    #+#              #
#    Updated: 2023/06/21 17:35:21 by kjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_BIN			:= bin
DIR_BUILD		:= build
DIR_SRC			:= src

MODULES_NAMES	:= ctype list stdio stdlib string math
CP				:= cp --verbose -u

all:
	@for module in $(MODULES_NAMES); do \
		$(MAKE) -C $(DIR_SRC)/$$module; \
		$(CP) $(DIR_SRC)/$$module/$(DIR_BIN)/libft_$$module.a $(DIR_BIN); \
	done

clean:
	@for module in $(MODULES_NAMES); do \
		$(MAKE) -C $(DIR_SRC)/$$module clean; \
	done

fclean:
	@for module in $(MODULES_NAMES); do \
		$(MAKE) -C $(DIR_SRC)/$$module fclean; \
		$(RM) $(DIR_BIN)/libft_$$module.a; \
	done

re: fclean $(NAME)

.PHONY: all clean fclean re
