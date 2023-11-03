/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:44:25 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_string.h"

static int	get_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**unset_var(char *var, char **env)
{
	int		i;
	int		j;
	char	**envp;

	envp = malloc(sizeof(char *) * get_env_len(env));
	if (!envp)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)))
		{
			envp[j] = ft_strdup(env[i]);
			if (!envp[j])
				return (NULL);
			j++;
		}
		free(env[i]);
		i++;
	}
	envp[j] = NULL;
	free(env);
	return (envp);
}

static int	check_var(char *var, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var))
			&& (env[i][ft_strlen(var)] == '=' || !env[i][ft_strlen(var)]))
			return (1);
		i++;
	}
	return (0);
}

char	**unset(char **args, char **env)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_var(args[i], env))
			env = unset_var(args[i], env);
		if (!env)
			return (NULL);
		i++;
	}
	return (env);
}
