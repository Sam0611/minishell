/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:31:53 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/21 22:48:17 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static void	redirs_destroy(t_list *redirs)
{
	t_redir	*redir;

	if (!redirs)
		return ;
	if (redirs->next)
		redirs_destroy(redirs->next);
	redir = (t_redir *) redirs->content;
	free(redir->file);
	free(redirs->content);
	free(redirs);
}

void	commands_destroy(t_list *commands)
{
	t_command	*cmd;
	int			i;
	t_list		*redirs;

	i = 0;
	if (!commands)
		return ;
	cmd = commands->content;
	if (commands->next)
		commands_destroy(commands->next);
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	redirs = cmd->redirs;
	redirs_destroy(redirs);
	free(cmd);
	free(commands);
}

void	sublist_destroy(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		sublist_destroy(lst->next);
	free(lst);
}
