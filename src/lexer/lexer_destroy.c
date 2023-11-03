/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:48:16 by smalloir          #+#    #+#             */
/*   Updated: 2023/09/06 12:53:01 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	token_destroy(t_token *token)
{
	free(token->text);
	free(token);
}

void	lexer_destroy(t_list *lexer)
{
	if (!lexer)
		return ;
	if (lexer->next)
		lexer_destroy(lexer->next);
	token_destroy(lexer->content);
	free(lexer);
}
