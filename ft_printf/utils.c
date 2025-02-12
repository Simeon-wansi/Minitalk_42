/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:07:36 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/05 21:16:11 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned int	num;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		num = -n;
		str[0] = '-';
	}
	else
		num = n;
	str = ft_char(str, num, len);
	return (str);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX && sign == 1)
			return (-1);
		if (res > ((long)INT_MAX + 1) && sign == -1)
			return (0);
		str++;
	}
	return ((int)(sign * res));
}
