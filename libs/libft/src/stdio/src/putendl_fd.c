/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:05:19 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 16:22:38 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	write(fd, s, str_len);
	write(fd, "\n", 1);
	return (str_len + 1);
}
