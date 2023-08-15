/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:20:17 by sbzizal           #+#    #+#             */
/*   Updated: 2022/12/28 15:34:40 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putall(char c, va_list p, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(p, int), len);
	else if (c == 's')
		ft_putstr(va_arg(p, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(p, int), len);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(p, unsigned int), 0, len);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(p, unsigned int), 1, len);
	else if (c == '%')
		ft_putchar('%', len);
	else if (c == 'u')
		ft_unsigned(va_arg(p, unsigned int), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_putadd(va_arg(p, unsigned long long), len);
	}
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && !str[i + 1])
			break ;
		if (str[i] == '%')
		{
			i++;
			ft_putall(str[i], ap, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
