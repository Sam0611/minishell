/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:31:31 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "minishell.h"
#include "parser.h"
#include "executer.h"
#include "builtins.h"
#include "ft_string.h"
#include "ft_stdio.h"

#define ERROR 1
#define PWD_NOT_FOUND 2

static int	change_oldpwd(char **env, int j)
{
	int		i;
	char	*oldpwd;

	oldpwd = ft_strdup(env[j] + 4);
	if (!oldpwd)
		return (0);
	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "OLDPWD=", 7))
		i++;
	if (!env || !env[i])
	{
		free(oldpwd);
		return (ERROR);
	}
	free(env[i]);
	env[i] = ft_strjoin("OLDPWD=", oldpwd);
	free(oldpwd);
	return (0);
}

static int	change_pwd(char **env)
{
	char	*pwd;
	int		size;
	int		i;

	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	if (!env[i])
		return (PWD_NOT_FOUND);
	size = PATH_MAX;
	pwd = malloc(sizeof(char) * size);
	if (!pwd)
		return (ERROR);
	if (getcwd(pwd, size) == NULL)
	{
		free(pwd);
		return (0);
	}
	change_oldpwd(env, i);
	free(env[i]);
	env[i] = ft_strjoin("PWD=", pwd);
	free(pwd);
	return (0);
}

char	**cd(char **args, char **env)
{
	int	ac;

	ac = 0;
	while (args[ac])
		ac++;
	if (ac > 2)
	{
		print_error("cd: too many arguments", ERR_ARG);
		return (env);
	}
	if (ac == 1)
		return (env);
	if (chdir(args[1]))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_error(args[1], ERR_ARG);
		return (env);
	}
	if (change_pwd(env) == PWD_NOT_FOUND)
		env = unset_var("OLDPWD", env);
	return (env);
}
