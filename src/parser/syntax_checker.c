/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:48:16 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/21 22:41:03 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include <unistd.h>

int	check_pipes(t_list *lexer)
{
	t_token			*token;
	t_token_type	prev_type;

	prev_type = TOKEN_PIPE;
	while (lexer)
	{
		token = (t_token *) lexer->content;
		if (token->type == TOKEN_PIPE
			&& (prev_type == TOKEN_PIPE || !lexer->next))
		{
			g_exit_code = ERR_SYNTAX;
			write(2, "Syntax error\n", 13);
			return (1);
		}
		prev_type = token->type;
		lexer = lexer->next;
	}
	return (0);
}

static int	is_bracket(t_token_type type)
{
	if (type == TOKEN_GREATER || type == TOKEN_GREATER_GREATER)
		return (1);
	if (type == TOKEN_LESSER || type == TOKEN_LESSER_LESSER)
		return (1);
	return (0);
}

int	check_brackets(t_list *lexer)
{
	t_token			*token;
	t_token_type	prev_type;

	prev_type = TOKEN_GENERAL;
	while (lexer)
	{
		token = (t_token *) lexer->content;
		if ((token->type == TOKEN_PIPE && is_bracket(prev_type))
			|| (is_bracket(token->type) && (!lexer->next
					|| is_bracket(prev_type))))
		{
			g_exit_code = ERR_SYNTAX;
			write(2, "Syntax error\n", 13);
			return (1);
		}
		prev_type = token->type;
		lexer = lexer->next;
	}
	return (0);
}
