/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:42:07 by kjimenez          #+#    #+#             */
/*   Updated: 2023/09/06 12:29:27 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "ft_string.h"
#include <unistd.h>

int	count_quotes(char *str, int len)
{
	int	i;
	int	j;
	int	quote;

	i = 0;
	j = 0;
	quote = 0;
	if (ft_strchr("|<>", *str))
		return (0);
	while (j < len || str[i] == CHAR_QUOTE || str[i] == CHAR_DQUOTE)
	{
		if ((str[i] == CHAR_QUOTE || str[i] == CHAR_DQUOTE) && quote == 0)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		else
			j++;
		i++;
	}
	return (i - len);
}

static int	ignore_quotes(char *str, int i)
{
	char	quote;

	quote = str[i];
	i++;
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			i = ignore_quotes(str, i);
		if (!str[i])
		{
			g_exit_code = 2;
			write(2, "Syntax error : quotes not closed\n", 33);
			return (1);
		}
		i++;
	}
	return (0);
}
