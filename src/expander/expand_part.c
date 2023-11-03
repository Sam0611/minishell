/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:06:35 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/31 17:50:29 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_ctype.h"
#include "ft_stdlib.h"

char	*ft_getenv(char *var, char **env);
char	*replace_word(char *str, int start_index, int end_index,
			char *new_word);

static int	is_env_char(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

static char	*get_part_from_str(char *str, int start_index, int end_index)
{
	int		i;
	int		j;
	char	*part_from_str;

	i = 0;
	j = 0;
	part_from_str = malloc((end_index - start_index) + 2);
	if (!part_from_str)
		return (NULL);
	while (str[i])
	{
		if (i >= start_index && i <= end_index)
		{
			part_from_str[j] = str[i];
			j++;
		}
		i++;
	}
	part_from_str[j] = '\0';
	return (part_from_str);
}

static void	expand_str_part_env_var(char **expanded_str, int *i, int j,
	char **env)
{
	char	*temp_expanded_str;
	char	*expanded_env_var;
	char	*env_var;

	temp_expanded_str = *expanded_str;
	env_var = get_part_from_str(*expanded_str, *i + 1, j - 1);
	expanded_env_var = ft_getenv(env_var, env);
	if (expanded_env_var == NULL)
	{
		*expanded_str = replace_word(*expanded_str, *i, j - 1, "");
		(*i)--;
	}
	else
		*expanded_str = replace_word(*expanded_str, *i, j - 1,
				expanded_env_var);
	free(env_var);
	free(temp_expanded_str);
}

static void	expand_str_part_exit_code(char **expanded_str, int i, int j)
{
	char	*temp_expanded_str;
	char	*exit_code_as_str;

	temp_expanded_str = *expanded_str;
	exit_code_as_str = ft_itoa(g_exit_code);
	*expanded_str = replace_word(*expanded_str, i, j, exit_code_as_str);
	free(exit_code_as_str);
	free(temp_expanded_str);
}

void	expand_str_part(char **expanded_str, int *i, char **env)
{
	int		j;

	j = *i + 1;
	if ((*expanded_str)[j] == '?')
	{
		expand_str_part_exit_code(expanded_str, *i, j);
		return ;
	}
	while ((*expanded_str)[j] && is_env_char((*expanded_str)[j]))
		j++;
	if (*i != (j - 1))
		expand_str_part_env_var(expanded_str, i, j, env);
}
