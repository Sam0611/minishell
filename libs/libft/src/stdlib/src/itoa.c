/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:11:22 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:29:53 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	count_digits(int number)
{
	long		number_long;
	size_t		digits;

	number_long = number;
	if (number_long < 0)
		number_long = -number_long;
	digits = 0;
	while (number_long > 0)
	{
		number_long /= 10;
		digits++;
	}
	return (digits);
}

static char	*ft_itoa_zero(void)
{
	char	*number_str;

	number_str = malloc(2 * sizeof(char));
	number_str[0] = '0';
	number_str[1] = '\0';
	return (number_str);
}

char	*ft_itoa(int n)
{
	size_t	digit_count;
	char	*number_str;
	long	n_long;

	n_long = n;
	if (n_long == 0)
		return (ft_itoa_zero());
	digit_count = count_digits(n);
	number_str = malloc((digit_count + (n < 0) + 1) * sizeof(char));
	if (!number_str)
		return (NULL);
	if (n < 0)
	{
		number_str[0] = '-';
		n_long = -n_long;
	}
	number_str[digit_count + (n < 0)] = '\0';
	while (digit_count > 0)
	{
		number_str[(digit_count - 1) + (n < 0)] = (n_long % 10) + '0';
		n_long /= 10;
		digit_count--;
	}
	return (number_str);
}
