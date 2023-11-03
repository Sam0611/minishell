/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/27 19:16:12 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_stdio.h"
#include <unistd.h>

int	ft_error(char *message, int exit_code)
{
	if (g_exit_code == ERR_SIGINT)
		return (1);
	perror(message);
	g_exit_code = exit_code;
	return (1);
}

int	print_error(char *message, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	if (exit_code == ERR_CMD)
		ft_putstr_fd(": command not found", 2);
	if (exit_code == ERR_DIR)
		ft_putstr_fd(": Is a directory", 2);
	write(2, "\n", 1);
	g_exit_code = exit_code;
	return (1);
}
