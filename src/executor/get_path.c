/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 03:47:08 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/27 19:15:32 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "parser.h"
#include "executer.h"
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

static int	ft_strsearch(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*check_cmd(char *env, char *cmd)
{
	int		i;
	int		e;
	int		len;
	char	*str[3];

	i = 5;
	e = -1;
	while (env && e == -1 && env[i - 1] && cmd[0])
	{
		len = ft_strsearch(env + i, ':');
		str[0] = ft_substr(env, i, len);
		str[1] = ft_strjoin(str[0], "/");
		free(str[0]);
		str[2] = ft_strjoin(str[1], cmd);
		free(str[1]);
		if (!str[2])
			return (NULL);
		i += len + 1;
		e = access(str[2], F_OK);
		if (e == -1)
			free(str[2]);
	}
	if (e == -1)
		return (NULL);
	return (str[2]);
}

static int	check_file_error(char *cmd)
{
	DIR		*dir;
	int		check;

	check = access(cmd, X_OK);
	if (errno == 13 && (!ft_strncmp(cmd, "./", 2) || cmd[0] == '/'))
	{
		ft_putstr_fd("minishell: ", 2);
		return (ft_error(cmd, ERR_PERM));
	}
	if (check && (!ft_strncmp(cmd, "./", 2) || cmd[0] == '/'))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_code = ERR_CMD;
		return (1);
	}
	dir = opendir(cmd);
	if (!dir)
		return (0);
	print_error(cmd, ERR_DIR);
	closedir(dir);
	return (1);
}

char	*get_path(t_command cmd, char **env)
{
	int		i;
	char	*path;

	if (check_file_error(cmd.args[0]))
		return (NULL);
	path = ft_strdup(cmd.args[0]);
	if (!path)
		return (NULL);
	if (access(path, X_OK) != -1)
		return (path);
	free(path);
	i = 0;
	while (env && env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env)
		return (NULL);
	path = check_cmd(env[i], cmd.args[0]);
	if (!path)
	{
		print_error(cmd.args[0], ERR_CMD);
		return (NULL);
	}
	return (path);
}
