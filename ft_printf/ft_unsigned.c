/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:41:43 by sbzizal           #+#    #+#             */
/*   Updated: 2022/11/18 01:49:31 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int nb, int *len)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48, len);
	}
	else if (nb > 9)
	{
		ft_unsigned(nb / 10, len);
		ft_unsigned(nb % 10, len);
	}
}
