/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:58:00 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/11 13:58:52 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
