/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:51:15 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 16:25:21 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_putnbr_fd(int nb, int fd, int recursive_pass)
{
	long		nb_long;
	static int	printed_count;

	if (!recursive_pass)
		printed_count = 0;
	nb_long = (long) nb;
	if (nb_long < 0)
	{
		printed_count += ft_putchar_fd('-', fd);
		nb_long = -nb_long;
	}
	if (nb_long < 10)
		printed_count += ft_putchar_fd(nb_long + '0', fd);
	else
	{
		ft_putnbr_fd(nb_long / 10, fd, 1);
		ft_putnbr_fd(nb_long % 10, fd, 1);
	}
	return (printed_count);
}
