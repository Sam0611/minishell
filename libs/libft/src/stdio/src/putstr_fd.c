/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:41:22 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 16:27:29 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	write(fd, s, str_len);
	return (str_len);
}
