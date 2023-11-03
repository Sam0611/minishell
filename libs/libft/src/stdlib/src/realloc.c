/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:08:02 by kjimenez          #+#    #+#             */
/*   Updated: 2023/06/23 00:47:09 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!*ptr)
		return (NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, *ptr, old_size);
	free(*ptr);
	*ptr = new_ptr;
	return (*ptr);
}
