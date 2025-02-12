/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:03:08 by sngantch          #+#    #+#             */
/*   Updated: 2025/01/01 20:40:01 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str = malloc(s1_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len + 1);
	return (str);
}

char	*ft_char(char *s, unsigned int num, int len)
{
	while (num > 0)
	{
		s[len--] = '0' + (num % 10);
		num /= 10;
	}
	return (s);
}

int	ft_count(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
