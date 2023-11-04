/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/11/04 19:57:36 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_string.h"
#include "parser.h"
#include "executer.h"

#define ERROR 1
#define PATH_NOT_FOUND 2
#define BUILTIN_ENV 2

int		is_builtin(char **args);
char	*check_cmd(char *env, char *cmd);

static int	check_path(t_params *vars, char **args)
{
	int		i;
	char	*path;

	i = 0;
	while (vars->env && vars->env[i] && ft_strncmp(vars->env[i], "PATH=", 5))
		i++;
	if (!vars->env)
		return (ERROR);
	if (access(args[0], F_OK) != -1)
		path = ft_strdup(args[0]);
	else
		path = check_cmd(vars->env[i], args[0]);
	if (!path)
		return (PATH_NOT_FOUND);
	free(path);
	return (0);
}

static int	check_redir(t_list *uncasted_command)
{
	t_command	*cmd;
	t_redir		*redir;
	t_list		*uncasted_redir;

	cmd = (t_command *) uncasted_command->next->content;
	uncasted_redir = cmd->redirs;
	while (uncasted_redir)
	{
		redir = (t_redir *) uncasted_redir->content;
		if (redir->type == REDIR_IN || redir->type == REDIR_IN_HEREDOC)
			return (1);
		uncasted_redir = uncasted_redir->next;
	}
	return (0);
}

int	open_pipes(t_list *uncasted_command, t_params *vars)
{
	t_command	*cmd;

	if (pipe(vars->pipe_fd) == -1)
		return (ERROR);
	if (!uncasted_command->next)
		return (0);
	cmd = (t_command *) uncasted_command->next->content;
	if (check_redir(uncasted_command) || is_builtin(cmd->args) == BUILTIN_ENV
		|| check_path(vars, cmd->args) == PATH_NOT_FOUND)
	{
		close(vars->pipe_fd[1]);
		vars->pipe_fd[1] = open("/dev/null", O_WRONLY);
		if (vars->pipe_fd[1] < 0)
			return (ERROR);
	}
	return (0);
}
