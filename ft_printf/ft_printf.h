/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:47:21 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/05 21:15:15 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_puthex(unsigned int num, const char format);
int		ft_putptr(uintptr_t ptr);
int		ft_putunsigned(int nb);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);
char	*ft_char(char *s, unsigned int num, int len);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
int		ft_count(int n);
int		ft_atoi(const char *str);

#endif