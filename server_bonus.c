/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:30:44 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 17:11:17 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig, siginfo_t *info, void *uap)
{
	static char	sym;
	static int	bit;

	uap = (void *)uap;
	if (sig == SIGUSR1)
	{
		sym = (sym << 1);
		bit++;
		usleep(100);
		send_answer(info);
	}
	else if (sig == SIGUSR2)
	{
		sym = (sym << 1) + 1;
		bit++;
		usleep(100);
		send_answer(info);
	}
	if (bit > 7)
	{
		write(1, &sym, 1);
		sym = 0;
		bit = 0;
	}
}

static void	giveme_sig(struct sigaction *act)
{
	act->sa_sigaction = &signal_handler;
	act->sa_flags = SA_SIGINFO;
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					ppid;

	argv = (void *)argv;
	ppid = getpid();
	ft_putnbr(ppid);
	if (argc != 1)
	{
		write(1, "NOT VALID\n", 10);
		exit (0);
	}
	giveme_sig(&act);
	while (1)
		pause();
}
