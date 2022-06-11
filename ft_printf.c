/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:24:25 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/11 13:58:54 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

static void	ft_putchar(char c, int *counter);
static void	ft_putstr(const char *str, int *counter);

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
			if (*format == 's' && format++)
				ft_putstr(va_arg(ap, char *), &counter);
			else if (*format == 'c' && format++)
				ft_putchar(va_arg(ap, int), &counter);
			else if (*format == '%' && format++)
				ft_putstr("%", &counter);
			else
			{
				if (*format == 'p')
					ft_putstr("0x", &counter);
				ft_putstr(ft_convert(va_arg(ap, long int),
						*format++), &counter);
			}
		}
	}
	return (counter);
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
