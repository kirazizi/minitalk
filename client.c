/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:56:55 by sbzizal           #+#    #+#             */
/*   Updated: 2022/12/29 13:17:09 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	return (res * signe);
}

void	ft_chartobin(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c << 1;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf("%sError, Wrong number of arguments\n", RED);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	if (av[2][i] == 0)
		exit(0);
	while ((av[2])[i])
	{
		ft_chartobin(av[2][i], pid);
		i++;
	}
	ft_chartobin('\0', pid);
	return (0);
}
