/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/25 19:48:44 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "parser.h"
#include "executer.h"
#include "signal_handler.h"
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

static int	get_heredoc_fd(char *limiter)
{
	char	*str;
	int		pipefd[2];
	int		len;

	g_exit_code = dup(0);
	signal(SIGINT, sigint_in_heredoc);
	len = ft_strlen(limiter);
	if (pipe(pipefd) == -1)
		return (-1);
	str = get_next_line(g_exit_code);
	while (str && (ft_strncmp(limiter, str, len) || str[len] != '\n'))
	{
		write(pipefd[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(g_exit_code);
	}
	free(str);
	if (g_exit_code != ERR_SIGINT)
	{
		close(g_exit_code);
		g_exit_code = 0;
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

static void	check_heredoc(t_list *uncasted_redir)
{
	t_redir		*redir;
	int			fd;

	while (uncasted_redir)
	{
		redir = (t_redir *) uncasted_redir->content;
		if (redir->type == REDIR_IN_HEREDOC)
		{
			fd = get_heredoc_fd(redir->file);
			close(fd);
		}
		uncasted_redir = uncasted_redir->next;
	}
}

static void	check_redir_type(t_redir_type type, int *fd)
{
	if (fd[0] > 0 && (type == REDIR_IN || type == REDIR_IN_HEREDOC))
		close(fd[0]);
	if (fd[1] > 1 && (type == REDIR_OUT || type == REDIR_OUT_APPEND))
		close(fd[1]);
}

int	open_files(t_list *uncasted_redir, int *fd)
{
	t_redir		*redir;

	while (uncasted_redir)
	{
		redir = (t_redir *) uncasted_redir->content;
		check_redir_type(redir->type, fd);
		if (redir->type == REDIR_IN)
			fd[0] = open(redir->file, O_RDONLY);
		if (redir->type == REDIR_IN_HEREDOC)
			fd[0] = get_heredoc_fd(redir->file);
		if (redir->type == REDIR_OUT)
			fd[1] = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (redir->type == REDIR_OUT_APPEND)
			fd[1] = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (g_exit_code == ERR_SIGINT)
			return (1);
		if (fd[0] < 0 || fd[1] < 0)
		{
			check_heredoc(uncasted_redir);
			return (ft_error(redir->file, ERR_FILE));
		}
		uncasted_redir = uncasted_redir->next;
	}
	return (0);
}
