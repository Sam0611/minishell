/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:31:53 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/21 22:48:17 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SPLIT THE MAIN LIST OF TOKENS INTO SUBLIST OF TOKENS AT PIPE TOKEN
IN EACH SUBLIST FIND EVERY TOKEN RELATED TO REDIRECTION (<, <<, >, >>)
AND USE THE NEXT TOKEN TO CREATE A REDIRECTION AND ADD IT TO THE REDIRECTION
ARRAY OF THE COMMAND, PROCEED TO REMOVE THE TOKENS FROM THE SUBLIST
ALL TOKENS REMAINING IN THE SUBLIST ARE THE ARGS OF THE COMMAND THAT
WE CAN SEND TO EXECVE OR USE TO RESOLVE THE CORRESPONDING BUILTIN
*/

#include "minishell.h"
#include "ft_string.h"
#include "lexer.h"
#include "parser.h"

t_list			*get_redirections(t_list *cmd_tokens);
t_redir_type	get_redir_type(t_token *token);
int				check_pipes(t_list *lexer);
int				check_brackets(t_list *lexer);
void			sublist_destroy(t_list *lst);

static t_list	*split_tokens(t_list *lexer)
{
	t_list	*tokens_sublists;
	t_list	*tokens_list;
	t_list	*temp_lexer;
	t_token	*token;

	temp_lexer = lexer;
	tokens_list = NULL;
	tokens_sublists = NULL;
	while (temp_lexer)
	{
		token = (t_token *) temp_lexer->content;
		if (token->type == TOKEN_PIPE)
		{
			ft_lstadd_back(&tokens_sublists, ft_lstnew(tokens_list));
			tokens_list = NULL;
		}
		else
			ft_lstadd_back(&tokens_list, ft_lstnew(token));
		temp_lexer = temp_lexer->next;
	}
	ft_lstadd_back(&tokens_sublists, ft_lstnew(tokens_list));
	return (tokens_sublists);
}

static int	count_args(t_list *cmd_tokens)
{
	t_list			*temp_cmd_tokens;
	t_token			*token;
	t_redir_type	prev_redir_type;
	int				args_count;

	args_count = 0;
	temp_cmd_tokens = cmd_tokens;
	prev_redir_type = REDIR_UNKNOWN;
	while (temp_cmd_tokens)
	{
		token = (t_token *) temp_cmd_tokens->content;
		if (token->type == TOKEN_GENERAL
			&& prev_redir_type == REDIR_UNKNOWN)
			args_count++;
		prev_redir_type = get_redir_type(token);
		temp_cmd_tokens = temp_cmd_tokens->next;
	}
	return (args_count);
}

static char	**get_args(t_list *cmd_tokens)
{
	t_list			*temp_cmd_tokens;
	t_token			*token;
	t_redir_type	prev_redir_type;
	char			**args;
	int				args_count;

	args_count = 0;
	args = malloc((count_args(cmd_tokens) + 1)
			* sizeof(char *));
	temp_cmd_tokens = cmd_tokens;
	prev_redir_type = REDIR_UNKNOWN;
	while (temp_cmd_tokens)
	{
		token = (t_token *) temp_cmd_tokens->content;
		if (token->type == TOKEN_GENERAL
			&& prev_redir_type == REDIR_UNKNOWN)
		{
			args[args_count] = ft_strdup(token->text);
			args_count++;
		}
		prev_redir_type = get_redir_type(token);
		temp_cmd_tokens = temp_cmd_tokens->next;
	}
	args[args_count] = NULL;
	return (args);
}

static t_command	*command_new(char **args, t_list *redirs)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->args = args;
	command->redirs = redirs;
	return (command);
}

t_list	*get_commands(t_list *lexer)
{
	t_list	*cmds;
	t_list	*sublists;
	t_list	*tmp_sublists;
	char	**cmd_args;
	t_list	*cmd_redirections;

	if (check_pipes(lexer) || check_brackets(lexer))
		return (NULL);
	sublists = split_tokens(lexer);
	tmp_sublists = sublists;
	cmds = NULL;
	while (sublists)
	{
		cmd_args = get_args(sublists->content);
		cmd_redirections = get_redirections(sublists->content);
		ft_lstadd_back(&cmds, ft_lstnew(
				command_new(cmd_args, cmd_redirections)));
		sublist_destroy(sublists->content);
		sublists = sublists->next;
	}
	sublist_destroy(tmp_sublists);
	return (cmds);
}
