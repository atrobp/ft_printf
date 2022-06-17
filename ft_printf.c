/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:10:12 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/16 22:42:37 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convert(long long num, char wbase);
static void	negativecheck(long long *num);
static void	ft_putstr(const char *str);
static void	ft_putchar(char c);

int		g_final = 0;
char	g_reprensation[16] = "0123456789abcdef";
char	g_buffer[50];

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && format++)
		{
			if (*format == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*format == 'c')
				ft_putchar(va_arg(ap, int));
			else if (*format == '%')
				ft_putstr("%");
			else
				ft_putstr(ft_convert(va_arg(ap, long long), *format));
			format++;
		}
		else
			ft_putchar(*format++);
	}
	return (g_final);
}

static char	*ft_convert(long long num, char wbase)
{
	int		base;
	char	*str;

	str = &g_buffer[49];
	*str = '\0';
	base = 10;
	if (wbase == 'x' || wbase == 'X' || wbase == 'p')
		base = 16;
	if (wbase == 'p')
		ft_putstr("0x");
	if (num == 0)
		return ("0");
	if (num < 0)
		negativecheck(&num);
	while (num)
	{
		if (wbase == 'X' && num % base > 9)
			*--str = g_reprensation[num % base] - 32;
		else
			*-- str = g_reprensation[num % base];
		num /= base;
	}
	return (str);
}

static void	negativecheck(long long *num)
{
	*num = -*num;
	ft_putstr("-");
}

static void	ft_putstr(const char *str)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		ft_putchar(*str++);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_final += 1;
}
