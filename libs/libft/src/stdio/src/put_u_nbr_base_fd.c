/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_nbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:39:40 by kjimenez          #+#    #+#             */
/*   Updated: 2023/06/16 17:03:10 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

int	ft_put_u_nbr_base_fd(uintptr_t nbr, char *base, int fd, int recursive_pass)
{
	unsigned int	base_len;
	static int		printed_count;

	if (!recursive_pass)
		printed_count = 0;
	base_len = ft_strlen(base);
	if (nbr < base_len)
		printed_count += ft_putchar_fd(base[nbr], fd);
	else
	{
		ft_put_u_nbr_base_fd(nbr / base_len, base, fd, 1);
		ft_put_u_nbr_base_fd(nbr % base_len, base, fd, 1);
	}
	return (printed_count);
}
