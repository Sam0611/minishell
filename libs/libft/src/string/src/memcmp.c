/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:32:41 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:07 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	if (n == 0)
		return (0);
	s1_char = (unsigned char *) s1;
	s2_char = (unsigned char *) s2;
	i = 0;
	while (i < n - 1 && s1_char[i] == s2_char[i])
		i++;
	return ((unsigned char) s1_char[i] - s2_char[i]);
}
