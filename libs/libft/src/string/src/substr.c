/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:08:09 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:31:03 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_substr_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	malloc_len;
	char	*sub_str;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	malloc_len = ft_substr_len(s, start, len);
	sub_str = (char *) malloc((malloc_len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
