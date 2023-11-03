/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_nbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:26:07 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 16:36:57 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_put_u_nbr_fd(unsigned int nbr, int fd, int recursive_pass)
{
	static int	printed_count;

	if (!recursive_pass)
		printed_count = 0;
	if (nbr < 10)
		printed_count += ft_putchar_fd(nbr + '0', fd);
	if (nbr > 9)
	{
		ft_put_u_nbr_fd(nbr / 10, fd, 1);
		ft_put_u_nbr_fd(nbr % 10, fd, 1);
	}
	return (printed_count);
}
