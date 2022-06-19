/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:24:02 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/12 15:24:02 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convertif(unsigned long num, char wbase);
static char	*ft_convertelse(unsigned int num, char wbase);
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
			else if (*format == 'p')
				ft_putstr(ft_convertif(va_arg(ap, long), *format));
			else
				ft_putstr(ft_convertelse(va_arg(ap, int), *format));
			format++;
		}
		else
			ft_putchar(*format++);
	}
	return (g_final);
}

static char	*ft_convertif(unsigned long num, char wbase)
{
	char	*str;

	str = &g_buffer[49];
	*str = '\0';
	if (wbase == 'p')
		ft_putstr("0x");
	if (num == 0)
		return ("0");
	while (num)
	{
		if (wbase == 'X' && num % 16 > 9)
			*--str = g_reprensation[num % 16] - 32;
		else
			*-- str = g_reprensation[num % 16];
		num /= 16;
	}
	return (str);
}

static char	*ft_convertelse(unsigned int num, char wbase)
{
	int		base;
	char	*str;

	str = &g_buffer[49];
	*str = '\0';
	base = 10;
	if (wbase == 'x' || wbase == 'X')
		base = 16;
	if ((wbase == 'i' || wbase == 'd') && (int)num < 0)
	{
		num = (int)-num;
		ft_putstr("-");
	}
	if (num == 0)
		return ("0");
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
