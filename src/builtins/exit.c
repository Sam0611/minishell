/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:25:11 by smalloir          #+#    #+#             */
/*   Updated: 2023/10/22 22:34:57 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_stdlib.h"

static int	is_a_numeric_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **args)
{
	int	exit_code;

	printf("exit\n");
	if (!*args)
		return (-1);
	if (!is_a_numeric_argument(*args))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(*args, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (-3);
	}
	if (args[1])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit_code = ft_atoi(*args);
	if (exit_code > 0)
		exit_code %= 256;
	while (exit_code < 0)
		exit_code = 256 + exit_code;
	return ((exit_code + 1) * -1);
}
