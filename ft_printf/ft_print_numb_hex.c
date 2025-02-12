/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numb_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:52:12 by sngantch          #+#    #+#             */
/*   Updated: 2025/01/01 21:29:50 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
		}
	}
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (hex_len(num));
}
