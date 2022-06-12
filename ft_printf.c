/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:24:25 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/11 20:09:45 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

static void	ft_putchar(char c, int *counter);
static void	ft_putstr(const char *str, int *counter);
static char	*ft_convert(long unsigned int num, char wbase);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	va_start(ap, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%' && *format + 1 == 's' && format++)
			ft_putstr(va_arg(ap, char *), &counter);
		else if (*format == '%' && *format + 1 == 'c' && format++)
			ft_putchar(va_arg(ap, int), &counter);
		else if (*format == '%' && *format + 1 == '%' && format++)
			ft_putstr("%", &counter);
		else
		{
			if (*format == '%' && *format + 1 == 'p' && format++)
				ft_putstr("0x", &counter);
			ft_putstr(ft_convert(va_arg(ap, long int),
					*format++), &counter);
		}
		else
			ft_putchar(*format++, &counter);
	}
	return (counter);
}

char	*ft_convert(long unsigned int num, char wbase)
{
	static char	reprensation[16] = "0123456789abcdef";
	static char	buffer[50];
	char		*str;
	int			base;

	str = &buffer[49];
	*str = '\0';
	if (wbase == 'x' || wbase == 'X' || wbase == 'p')
		base = 16;
	else if (wbase == 'd' || wbase == 'i')
		base = 10;
	else
		base = 8;
	while (num)
	{
		if (wbase == 'X' && num % base > 9)
			*--str = reprensation[num % base] - 32;
		else
			*--str = reprensation[num % base];
		num /= base;
	}
	return (str);
}

static void	ft_putstr(const char *str, int *counter)
{
	while (*str)
		ft_putchar(*str++, counter);
}

static void	ft_putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}
