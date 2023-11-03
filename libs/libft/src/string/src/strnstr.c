/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:36:50 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:45 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	if (ft_strncmp(s2, "", ft_strlen(s2)) == 0)
		return ((char *) s1);
	if (n == 0)
		return (0);
	s2_len = ft_strlen(s2);
	if (s2_len == 0 || n == 0)
		return ((char *) s1);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s2_len == j)
			return ((char *) &s1[i]);
		i++;
	}
	return (NULL);
}
