/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:24:53 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:32 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len + size);
	dst_len = ft_strlen(dst);
	if (size == 0 || size - 1 < dst_len)
		return (src_len + size);
	size = size - dst_len;
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
