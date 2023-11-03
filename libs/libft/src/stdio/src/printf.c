/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:30:01 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/13 12:21:03 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdarg.h>

static void	ft_printf_write_ptr(int *printed_count, va_list	*list)
{
	intptr_t	ptr_identifier;

	ptr_identifier = va_arg(*list, uintptr_t);
	if (!ptr_identifier)
		*printed_count += ft_putstr_fd("(nil)", 1);
	else
	{
		*printed_count += ft_putstr_fd("0x", 1);
		*printed_count += ft_put_u_nbr_base_fd(ptr_identifier,
				"0123456789abcdef", 1, 0);
	}
}

static void	ft_printf_write_str(int *printed_count, va_list	*list)
{
	char		*str_identifier;

	str_identifier = va_arg(*list, char *);
	if (!str_identifier)
		str_identifier = "(null)";
	*printed_count += ft_putstr_fd(str_identifier, 1);
}

static void	ft_printf_write(char c, int *printed_count, va_list	*list)
{
	if (c == 'c')
		*printed_count += ft_putchar_fd(va_arg(*list, int), 1);
	else if (c == 's')
		ft_printf_write_str(printed_count, list);
	else if (c == 'p')
		ft_printf_write_ptr(printed_count, list);
	else if (c == 'd' || c == 'i')
		*printed_count += ft_putnbr_fd(va_arg(*list, int), 1, 0);
	else if (c == 'u')
		*printed_count += ft_put_u_nbr_fd(va_arg(*list, int), 1, 0);
	else if (c == 'x')
		*printed_count += ft_put_u_nbr_base_fd(va_arg(*list, unsigned int),
				"0123456789abcdef", 1, 0);
	else if (c == 'X')
		*printed_count += ft_put_u_nbr_base_fd(va_arg(*list, unsigned int),
				"0123456789ABCDEF", 1, 0);
	else if (c == '%')
		*printed_count += ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		printed_count;

	if (!str)
		return (-1);
	i = 0;
	printed_count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_printf_write(str[i + 1], &printed_count, &list);
			i = i + 2;
		}
		else
		{
			printed_count += ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(list);
	return (printed_count);
}
