/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:45:19 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:10 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_dereference;
	const char	*src_dereference;

	dest_dereference = dest;
	src_dereference = src;
	i = 0;
	if (!src_dereference && !dest_dereference)
		return (dest);
	while (i < n)
	{
		dest_dereference[i] = src_dereference[i];
		i++;
	}
	return (dest);
}
