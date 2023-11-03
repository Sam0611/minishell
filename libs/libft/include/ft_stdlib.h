/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:14:56 by kjimenez          #+#    #+#             */
/*   Updated: 2023/06/23 00:51:58 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_realloc(void **ptr, size_t old_size, size_t new_size);
char	*ft_itoa(int n);

#endif
