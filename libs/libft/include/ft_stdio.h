/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:13:45 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/09 17:27:36 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int recursive_pass);
int		ft_put_u_nbr_fd(unsigned int nbr, int fd, int recursive_pass);
int		ft_put_u_nbr_base_fd(uintptr_t nbr, char *base, int fd,
			int recursive_pass);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);

#endif
