/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/09/11 15:38:58 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "ft_string.h"

#define BUILTIN_SIMPLE 1
#define BUILTIN_ENV 2

int	is_builtin(char **args)
{
	char	*cmd;

	cmd = args[0];
	if (!ft_strcmp(cmd, "pwd"))
		return (BUILTIN_SIMPLE);
	if (!ft_strcmp(cmd, "echo"))
		return (BUILTIN_SIMPLE);
	if (!ft_strcmp(cmd, "env"))
		return (BUILTIN_SIMPLE);
	if (!ft_strcmp(cmd, "export") && !args[1])
		return (BUILTIN_SIMPLE);
	if (!ft_strcmp(cmd, "export"))
		return (BUILTIN_ENV);
	if (!ft_strcmp(cmd, "unset"))
		return (BUILTIN_ENV);
	if (!ft_strcmp(cmd, "cd"))
		return (BUILTIN_ENV);
	if (!ft_strcmp(cmd, "exit"))
		return (BUILTIN_ENV);
	return (0);
}

int	exec_builtins(char **args, char **env)
{
	char	*cmd;

	cmd = args[0];
	if (!ft_strcmp(cmd, "pwd"))
		pwd();
	else if (!ft_strcmp(cmd, "echo"))
		echo(args);
	else if (!ft_strcmp(cmd, "env"))
		display_env(args, env);
	else if (!ft_strcmp(cmd, "export") && !args[1])
		display_env_export(env);
	else if (ft_strcmp(cmd, "cd") && ft_strcmp(cmd, "exit")
		&& ft_strcmp(cmd, "export") && ft_strcmp(cmd, "unset"))
		return (0);
	return (1);
}

char	**builtins_changing_env(char **args, char **env)
{
	char	*cmd;

	cmd = args[0];
	if (!ft_strcmp(cmd, "cd"))
		env = cd(args, env);
	if (!ft_strcmp(cmd, "export"))
		env = export(args + 1, env);
	if (!ft_strcmp(cmd, "unset"))
		env = unset(args + 1, env);
	if (!ft_strcmp(cmd, "exit"))
		g_exit_code = ft_exit(args + 1);
	return (env);
}
