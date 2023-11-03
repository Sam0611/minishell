/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:14:32 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:30:58 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	set_contains(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && set_contains(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && set_contains(set, s1[end - 1]))
		end--;
	trimmed_str = malloc((end - start + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i] = s1[start];
		i++;
		start++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
