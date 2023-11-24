/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:33:03 by kjimenez          #+#    #+#             */
/*   Updated: 2023/10/21 22:37:28 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static void	insert_word_in_str_before(char *str, char *str_with_word, int *i,
	int start_index)
{
	while (*i < start_index)
	{
		str_with_word[*i] = str[*i];
		(*i)++;
	}
}

static void	insert_word_in_str_after(char *str, char *str_with_word, int *i,
	int j)
{
	while (str[*i - j])
	{
		str_with_word[*i] = str[*i - j];
		(*i)++;
	}
}

static char	*insert_word_in_str(char *str, char *word, int start_index)
{
	int		i;
	int		j;
	char	*str_with_word;

	str_with_word = malloc(ft_strlen(str) + ft_strlen(word) + 1);
	if (!str_with_word)
		return (NULL);
	i = 0;
	insert_word_in_str_before(str, str_with_word, &i, start_index);
	j = 0;
	while (word[j])
	{
		str_with_word[i] = word[j];
		j++;
		i++;
	}
	insert_word_in_str_after(str, str_with_word, &i, j);
	str_with_word[i] = '\0';
	return (str_with_word);
}

static char	*delete_part_from_str(char *str, int start_index, int end_index)
{
	int		i;
	int		j;
	int		index_len;
	char	*str_without_word;

	i = 0;
	j = 0;
	index_len = end_index - start_index;
	str_without_word = malloc(ft_strlen(str) - index_len);
	if (!str_without_word)
		return (NULL);
	while (str[i])
	{
		if (i < start_index || i > end_index)
		{
			str_without_word[j] = str[i];
			j++;
		}
		i++;
	}
	str_without_word[j] = '\0';
	return (str_without_word);
}

char	*replace_word(char *str, int start_index, int end_index,
	char *new_word)
{
	char	*str_with_removed_part;
	char	*str_with_word;

	str_with_removed_part = delete_part_from_str(str, start_index, end_index);
	str_with_word = insert_word_in_str(str_with_removed_part,
			new_word, start_index);
	free(str_with_removed_part);
	return (str_with_word);
}
