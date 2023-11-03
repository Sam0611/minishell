/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:47:38 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:19:16 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*dst;
	size_t	i;

	dst = str;
	i = 0;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return (str);
}
