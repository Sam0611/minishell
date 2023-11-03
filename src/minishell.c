/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:36 by smalloir          #+#    #+#             */
/*   Updated: 2023/09/11 19:04:26 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "expander.h"
#include "executer.h"
#include "signal_handler.h"
#include "ft_string.h"
#include <readline/readline.h>
#include <readline/history.h>

int	g_exit_code = 0;

static char	**copy_env(char **env)
{
	char	**envp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	envp = malloc(sizeof(char *) * (i + 1));
	if (!envp)
		return (NULL);
	envp[i] = NULL;
	i = 0;
	while (env[i])
	{
		envp[i] = ft_strdup(env[i]);
		if (!envp[i])
			return (NULL);
		i++;
	}
	return (envp);
}

static char	**interpret_command_line(char *line, char **envp)
{
	char	*expanded_line;
	t_list	*lexer;
	t_list	*commands;

	if (ft_strcmp(line, ""))
	{
		add_history(line);
		expanded_line = expand_str(line, envp);
		g_exit_code = 0;
		lexer = lexer_new(expanded_line);
		free(expanded_line);
		if (!lexer)
			return (envp);
		commands = get_commands(lexer);
		lexer_destroy(lexer);
		if (!commands)
			return (envp);
		envp = exec(commands, envp);
		commands_destroy(commands);
	}
	return (envp);
}

static void	free_env(char **envp)
{
	int	i;

	i = 0;
	rl_clear_history();
	if (g_exit_code < 0)
		g_exit_code = (g_exit_code + 1) * -1;
	if (!envp)
		return ;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp[i]);
	free(envp);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**envp;

	if (ac != 1)
		return (127);
	(void)av;
	envp = copy_env(env);
	if (!envp)
		return (1);
	while (g_exit_code >= 0)
	{
		signal(SIGINT, new_prompt_line);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell> ");
		if (line)
			envp = interpret_command_line(line, envp);
		else
		{
			printf("exit\n");
			break ;
		}
		free(line);
	}
	free_env(envp);
	return (g_exit_code);
}
