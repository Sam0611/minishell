/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:42:05 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/21 22:46:33 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "ft_string.h"

static t_redir	*redir_new(t_redir_type type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = ft_strdup(file);
	return (redir);
}

t_redir_type	get_redir_type(t_token *token)
{
	if (token->type == TOKEN_GREATER)
		return (REDIR_OUT);
	if (token->type == TOKEN_LESSER)
		return (REDIR_IN);
	if (token->type == TOKEN_GREATER_GREATER)
		return (REDIR_OUT_APPEND);
	if (token->type == TOKEN_LESSER_LESSER)
		return (REDIR_IN_HEREDOC);
	return (REDIR_UNKNOWN);
}

t_list	*get_redirections(t_list *cmd_tokens)
{
	t_redir_type	redir_type;
	t_list			*temp_cmd_tokens;
	t_token			*token;
	t_list			*cmd_redirections;
	t_redir			*redir;

	redir_type = REDIR_UNKNOWN;
	temp_cmd_tokens = cmd_tokens;
	cmd_redirections = NULL;
	while (temp_cmd_tokens)
	{
		token = (t_token *) temp_cmd_tokens->content;
		if (redir_type != REDIR_UNKNOWN)
		{
			redir = redir_new(redir_type, token->text);
			ft_lstadd_back(&cmd_redirections, ft_lstnew(redir));
		}
		redir_type = get_redir_type(token);
		temp_cmd_tokens = temp_cmd_tokens->next;
	}
	return (cmd_redirections);
}
