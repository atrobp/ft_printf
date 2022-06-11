/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:30:13 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/11 13:46:33 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_H
#define	FT_H
# include <unistd.h>
# include <stdarg.h>


int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
char	*ft_convert(unsigned int num, char wbase);

#endif
