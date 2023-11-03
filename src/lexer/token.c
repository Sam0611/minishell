/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:26:29 by kjimenez          #+#    #+#             */
/*   Updated: 2023/09/06 12:29:44 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_string.h"
#include <stdlib.h>

t_token	*token_new(char *text, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->text = ft_strdup(text);
	token->type = type;
	return (token);
}

void	add_token(t_list **lexer, t_token *token)
{
	if (!(*lexer))
		*lexer = ft_lstnew(token);
	else
		ft_lstadd_back(lexer, ft_lstnew(token));
}
