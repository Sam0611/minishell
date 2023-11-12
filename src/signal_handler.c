/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:39:24 by smalloir          #+#    #+#             */
/*   Updated: 2023/09/11 15:38:58 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal_handler.h"
#include <readline/readline.h>
#include <unistd.h>

// ctrl+C in general
void	new_prompt_line(int signal)
{
	(void)signal;
	g_exit_code = ERR_SIGINT;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// ctrl+C in heredoc
void	sigint_in_heredoc(int signal)
{
	(void)signal;
	printf("\n");
	close(0);
	g_exit_code = ERR_SIGINT;
}

// ctrl+C in command
void	sigint_in_cmd(int signal)
{
	(void)signal;
	g_exit_code = ERR_SIGINT;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

// ctrl+\ in command
void	sigquit_in_cmd(int signal)
{
	(void)signal;
	g_exit_code = ERR_SIGQUIT;
	printf("Quit (core dumped)\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}
