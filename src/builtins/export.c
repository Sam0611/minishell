/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:37:01 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_ctype.h"

static char	**export_var(char *var, char **env)
{
	int		i;
	char	**envp;

	i = 0;
	while (env[i])
		i++;
	envp = malloc(sizeof(char *) * (i + 2));
	if (!envp)
		return (NULL);
	envp[i + 1] = NULL;
	i = 0;
	while (env[i])
	{
		envp[i] = ft_strdup(env[i]);
		if (!envp[i])
			return (NULL);
		free(env[i]);
		i++;
	}
	free(env);
	envp[i] = ft_strdup(var);
	if (!envp[i])
		return (NULL);
	return (envp);
}

static char	**modify_value(char *var, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	j = 0;
	while (env[j])
	{
		if (var[i] && !ft_strncmp(env[j], var, i)
			&& (env[j][i] == '=' || !env[j][i]))
		{
			free(env[j]);
			env[j] = ft_strdup(var);
			return (env);
		}
		if (!var[i] && !ft_strncmp(env[j], var, i))
			return (env);
		j++;
	}
	return (export_var(var, env));
}

static int	check_var(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if ((i == 0 && ft_isdigit(var[i]))
			|| (!ft_isalnum(var[i]) && var[i] != '_'))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(var, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_exit_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

char	**export(char **args, char **env)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_var(args[i]))
			env = modify_value(args[i], env);
		if (!env)
			return (NULL);
		i++;
	}
	return (env);
}
