/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:01:14 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:23 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c >= 256)
		c -= 256;
	i = 0;
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
