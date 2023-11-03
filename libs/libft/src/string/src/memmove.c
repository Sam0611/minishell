/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:45:19 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:30:06 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	ft_memmove_back(char *dest, const char *src, size_t n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
}

static void	ft_memmove_front(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*dest_char;
	const char		*src_char;

	if (!dest && !src)
		return (NULL);
	dest_char = (char *) dest;
	src_char = (const char *) src;
	if (src_char < dest_char && dest_char < (src_char + n))
		ft_memmove_back(dest_char, src_char, n);
	else
		ft_memmove_front(dest_char, src_char, n);
	return (dest);
}
