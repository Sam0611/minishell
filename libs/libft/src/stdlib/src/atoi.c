/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:20:32 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/06 16:47:06 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static void	ft_atoi_whitespace(const char *nptr, size_t *i)
{
	while (nptr[*i] == '\t' || nptr[*i] == '\n' || nptr[*i] == '\v'
		|| nptr[*i] == '\f' || nptr[*i] == '\v'
		|| nptr[*i] == '\r' || nptr[*i] == ' ')
		(*i)++;
}

static int	ft_atoi_sign(const char *nptr, size_t *i)
{
	int		sign;
	size_t	sign_changed;

	sign = 1;
	sign_changed = 0;
	while (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (sign_changed)
			sign = 0;
		if (nptr[*i] == '-')
			sign = -sign;
		sign_changed = 1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	res;
	int		sign;

	i = 0;
	ft_atoi_whitespace(nptr, &i);
	sign = ft_atoi_sign(nptr, &i);
	res = 0;
	while (nptr[i] - '0' >= 0 && nptr[i] - '0' <= 9)
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
