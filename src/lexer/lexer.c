/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:48:16 by smalloir          #+#    #+#             */
/*   Updated: 2023/09/06 12:53:01 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_string.h"
#include "ft_list.h"

void	add_token(t_list **lexer, t_token *token);
t_token	*token_new(char *text, t_token_type type);
int		count_quotes(char *str, int len);
int		check_quotes(char *str);

static char	*get_content_for_token(char *str, int len)
{
	int		i;
	int		j;
	char	quote;
	char	*content;

	i = 0;
	j = 0;
	quote = 0;
	content = malloc(len + 1);
	content[len] = '\0';
	while (j < len)
	{
		if ((str[i] == CHAR_QUOTE || str[i] == CHAR_DQUOTE) && !quote)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		else
			content[j++] = str[i];
		i++;
	}
	return (content);
}

static int	get_token_length(char *str)
{
	int		len;
	int		i;
	int		quote;

	i = 0;
	len = 0;
	quote = 0;
	if (ft_strchr("<>", str[i]) && str[i] == str[i + 1])
		return (2);
	if (ft_strchr("|<>", *str))
		return (1);
	while (str[i] && (quote || !ft_strchr("| <>", str[i])))
	{
		if ((str[i] == CHAR_QUOTE || str[i] == CHAR_DQUOTE) && !quote)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		else
			len++;
		i++;
	}
	return (len);
}

static int	get_token_type(char *str)
{
	if (*str == '|')
		return (TOKEN_PIPE);
	if (*str == '>' && *str == *(str + 1))
		return (TOKEN_GREATER_GREATER);
	if (*str == '>')
		return (TOKEN_GREATER);
	if (*str == '<' && *str == *(str + 1))
		return (TOKEN_LESSER_LESSER);
	if (*str == '<')
		return (TOKEN_LESSER);
	return (TOKEN_GENERAL);
}

static t_token	*get_token(char *str, int len)
{
	int		type;
	char	*token_content;
	t_token	*token;

	type = get_token_type(str);
	token_content = get_content_for_token(str, len);
	token = token_new(token_content, type);
	free(token_content);
	return (token);
}

t_list	*lexer_new(char *input)
{
	t_token	*token;
	t_list	*lexer;
	int		i;
	int		len;

	i = 0;
	token = NULL;
	lexer = NULL;
	if (check_quotes(input))
		return (lexer);
	while (input[i])
	{
		if (input[i] == CHAR_SPACE || input[i] == CHAR_TAB)
		{
			i++;
			continue ;
		}
		len = get_token_length(input + i);
		token = get_token(input + i, len);
		add_token(&lexer, token);
		i += len + count_quotes(input + i, len);
	}
	return (lexer);
}
