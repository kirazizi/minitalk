/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:32:42 by sbzizal           #+#    #+#             */
/*   Updated: 2022/11/17 21:39:07 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, int i, int *len)
{
	char	*base;

	if (i == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16, i, len);
		ft_putnbr_hex(nb % 16, i, len);
	}
	if (nb < 16)
	{
		ft_putchar(base[nb], len);
	}
}
