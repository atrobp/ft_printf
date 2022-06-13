/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:24:25 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/12 22:41:10 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdio.h>

static char	*ft_convert(long int num, char wbase, int *counter);
static void	ft_putstr(const char *str, int *counter);
static void	ft_putchar(char c, int *counter);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	va_start(ap, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c' && format++)
				ft_putchar(va_arg(ap, int), &counter);
			else if (*format == 's' && format++)
				ft_putstr(va_arg(ap, char *), &counter);
			else if (*format == '%' && format++)
				ft_putstr("%", &counter);
			else
				ft_putstr(ft_convert(va_arg(ap, long int),
						*format++, &counter), &counter);
		}
		else
			ft_putchar(*format++, &counter);
	}
	return (counter);
}

int	main(void)
{
	int	i;

	i = 0;
	ft_printf(" %d\n", ft_printf("hello %p", &i));
	printf(" %d\n", printf("hello %p", &i));
	return (0);
}

char	*ft_convert(long int num, char wbase, int *counter)
{
	static char	reprensation[16] = "0123456789abcdef";
	static char	buffer[50];
	char		*str;
	int			base;

	str = &buffer[49];
	*str = '\0';
	base = 10;
	if (wbase == 'x' || wbase == 'X' || wbase == 'p')
		base = 16;
	if (num < 0)
		num = -num;
	while (num)
	{
		if (wbase == 'X' && num % base > 9)
			*--str = reprensation[num % base] - 32;
		else
			*--str = reprensation[num % base];
		num /= base;
	}
	if (wbase == 'p')
		ft_putstr("0x", counter);
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
