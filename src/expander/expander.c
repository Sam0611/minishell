/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:27:15 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/31 17:44:57 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

void	expand_str_part(char **expanded_str, int *i, char **env);

static void	reset_exit_code(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (str[i])
		g_exit_code = 0;
}

char	*expand_str(char *str, char **env)
{
	char	*expanded_str;
	int		i;
	int		dquote_mode;
	int		quote_mode;

	i = 0;
	quote_mode = 0;
	dquote_mode = 0;
	expanded_str = ft_strdup(str);
	while (expanded_str[i])
	{
		if (expanded_str[i] == '\'' && quote_mode)
			quote_mode = 0;
		else if (expanded_str[i] == '\"' && dquote_mode)
			dquote_mode = 0;
		else if (expanded_str[i] == '\'' && !dquote_mode)
			quote_mode = 1;
		else if (expanded_str[i] == '\"' && !quote_mode)
			dquote_mode = 1;
		else if (expanded_str[i] == '$' && !quote_mode)
			expand_str_part(&expanded_str, &i, env);
		i++;
	}
	reset_exit_code(str);
	return (expanded_str);
}
