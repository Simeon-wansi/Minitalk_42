/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:10:28 by sngantch          #+#    #+#             */
/*   Updated: 2025/01/01 20:29:29 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_convers(va_list arg, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		char_printed += ft_putptr(va_arg(arg, uintptr_t));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		char_printed += ft_putunsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		char_printed += ft_puthex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arg;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_convers(arg, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (char_printed);
}
