/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:48:46 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:04 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	size_t			s_len;
	char			*s_char;

	if (n == 0)
		return (NULL);
	if (c >= 256)
		c -= 256;
	s_char = (char *) s;
	s_len = ft_strlen(s_char);
	i = 0;
	if (c == '\0' && n >= s_len)
		return (&s_char[s_len]);
	while (i < n)
	{
		if (s_char[i] == c)
			return (&s_char[i]);
		i++;
	}
	return (NULL);
}
