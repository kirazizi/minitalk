/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:16:34 by sbzizal           #+#    #+#             */
/*   Updated: 2022/12/29 13:16:57 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int sig, siginfo_t *info, void *cont)
{
	static int		i;
	static char		c;
	static pid_t	client_id;

	if (client_id != info -> si_pid)
	{
		i = 7;
		c = 0;
		client_id = info -> si_pid;
	}
	if (sig == SIGUSR1)
		c = c | (1 << i);
	if (i == 0)
	{
		ft_printf("%c", c);
		if (c == 0)
		{
			kill(client_id, SIGUSR2);
		}
		c = 0;
		i = 7;
	}
	else
		i--;
	(void)cont;
}

int	main(int ac, char **av)
{
	struct sigaction	as;
	pid_t				pid;

	pid = getpid();
	ft_printf("%s %d\n", "sever pid :", pid);
	as.sa_sigaction = ft_sighandler;
	as.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &as, NULL);
	sigaction(SIGUSR2, &as, NULL);
	while (1)
	{
		pause();
	}
	(void)ac;
	(void)av;
}
