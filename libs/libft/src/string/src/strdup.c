/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:51:17 by kjimenez          #+#    #+#             */
/*   Updated: 2023/09/05 14:14:33 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	str_len;
	char	*duplicated_str;

	str_len = ft_strlen(s);
	duplicated_str = malloc((str_len + 1) * sizeof(char));
	if (!duplicated_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		duplicated_str[i] = s[i];
		i++;
	}
	duplicated_str[i] = '\0';
	return (duplicated_str);
}
