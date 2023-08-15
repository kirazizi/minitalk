/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:56:08 by sbzizal           #+#    #+#             */
/*   Updated: 2022/12/29 13:10:09 by sbzizal          ###   ########.fr       */
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
	ft_printf("%s %d\n", "server pid :", pid);
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
