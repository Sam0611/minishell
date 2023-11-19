/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:46:22 by kjimenez          #+#    #+#             */
/*   Updated: 2023/09/06 12:45:31 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "ft_list.h"

typedef enum e_char_type
{
	CHAR_QUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SPACE = ' ',
	CHAR_TAB = 9
}			t_char_type;

typedef enum e_token_type
{
	TOKEN_GENERAL = -1,
	TOKEN_PIPE = '|',
	TOKEN_GREATER = '>',
	TOKEN_LESSER = '<',
	TOKEN_GREATER_GREATER = 1,
	TOKEN_LESSER_LESSER = 2,
}			t_token_type;

typedef struct s_token
{
	char			*text;
	t_token_type	type;
}	t_token;

t_list	*lexer_new(char *input);
void	lexer_destroy(t_list *lexer);

#endif
