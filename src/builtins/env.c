/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:34:04 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "ft_stdio.h"
#include "ft_string.h"

void	display_env(char **args, char **env)
{
	int	i;

	i = 0;
	if (args[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_code = 127;
		return ;
	}
	while (env && env[i])
	{
		if (ft_strchr(env[i], '='))
			printf("%s\n", env[i]);
		i++;
	}
}

static int	is_lower(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s2[i] - s1[i] > 0)
		return (1);
	return (0);
}

static int	compare(char **env, char *prev)
{
	int	i;
	int	j;

	i = 0;
	while (prev && env[i] && !is_lower(prev, env[i]))
		i++;
	j = i;
	while (env[i])
	{
		if (is_lower(env[i], env[j]) && is_lower(prev, env[i]))
			j = i;
		i++;
	}
	return (j);
}

void	display_env_export(char **env)
{
	int		i;
	int		j;
	char	*var;

	var = NULL;
	i = -1;
	while (env && env[++i])
	{
		var = env[compare(env, var)];
		if (!ft_strncmp(var, "_=", 2))
			continue ;
		printf("declare -x ");
		j = 0;
		while (var[j] && var[j] != '=')
		{
			printf("%c", var[j]);
			j++;
		}
		if (var[j] == '=')
			printf("=\"%s\"", var + j + 1);
		printf("\n");
	}
}
