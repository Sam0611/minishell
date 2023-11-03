/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/28 17:01:49 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "executer.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "signal_handler.h"
#include <fcntl.h>
#include <sys/wait.h>

#define BUILTIN_SIMPLE 1
#define BUILTIN_ENV 2

int		open_files(t_list *uncasted_redir, int *fd);
char	*get_path(t_command cmd, char **env);
int		is_builtin(char **args);
int		exec_builtins(char **args, char **env);
char	**builtins_changing_env(char **args, char **env);

static void	exit_process(t_params *vars)
{
	int	i;

	i = 0;
	while (vars->env[i])
	{
		free(vars->env[i]);
		i++;
	}
	free(vars->env[i]);
	free(vars->env);
	commands_destroy(vars->cmd_beginning);
	exit(0);
}

static int	dup_and_close_fds(t_params *vars)
{
	int	error;

	error = 0;
	if (dup2(vars->file_fd[0], 0) == -1)
		error = ft_error("dup2", ERR_FCT);
	if (dup2(vars->file_fd[1], 1) == -1)
		error = ft_error("dup2", ERR_FCT);
	close(vars->file_fd[0]);
	close(vars->file_fd[1]);
	close(vars->pipe_fd[0]);
	close(vars->pipe_fd[1]);
	return (error);
}

static void	exec_in_child_process(t_command *cmd, t_params *vars)
{
	char	*path;
	int		pid;

	path = NULL;
	if (!is_builtin(cmd->args))
	{
		path = get_path(*cmd, vars->env);
		if (!path)
			return ;
	}
	signal(SIGINT, sigint_in_cmd);
	signal(SIGQUIT, sigquit_in_cmd);
	pid = fork();
	if (pid < 0)
		ft_error("minishell", ERR_FCT);
	if (pid == 0)
	{
		if (!dup_and_close_fds(vars))
			if (!exec_builtins(cmd->args, vars->env))
				execve(path, cmd->args, vars->env);
		exit_process(vars);
	}
	free(path);
}

static int	execute_cmd(t_list *uncasted_command, t_params *vars)
{
	t_command	*cmd;

	if (pipe(vars->pipe_fd) == -1)
		return (1);
	if (uncasted_command->next)
		vars->file_fd[1] = vars->pipe_fd[1];
	else
		vars->file_fd[1] = dup(1);
	cmd = (t_command *) uncasted_command->content;
	if (!open_files(cmd->redirs, vars->file_fd) && cmd->args[0])
	{
		if (is_builtin(cmd->args) == BUILTIN_ENV && !uncasted_command->next)
			vars->env = builtins_changing_env(cmd->args, vars->env);
		else
			exec_in_child_process(cmd, vars);
	}
	if (vars->file_fd[0] > 0 && vars->file_fd[0] != vars->pipe_fd[0])
		close(vars->file_fd[0]);
	if (vars->file_fd[1] > 0 && vars->file_fd[1] != vars->pipe_fd[1])
		close(vars->file_fd[1]);
	close(vars->pipe_fd[1]);
	if (uncasted_command->next)
		vars->file_fd[0] = vars->pipe_fd[0];
	return (0);
}

char	**exec(t_list *uncasted_command, char **env)
{
	t_params	vars;
	int			status;

	vars.env = env;
	vars.file_fd[0] = dup(0);
	vars.cmd_beginning = uncasted_command;
	while (uncasted_command && g_exit_code != ERR_SIGINT)
	{
		execute_cmd(uncasted_command, &vars);
		uncasted_command = uncasted_command->next;
	}
	close(vars.pipe_fd[0]);
	status = g_exit_code;
	while (waitpid(-1, &status, 0) != -1)
		continue ;
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	return (vars.env);
}
