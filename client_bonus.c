/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:37:49 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 17:29:47 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	serv_act(int sig, siginfo_t *info, void *uap)
{
	static int	sig_num;

	info = (void *)info;
	uap = (void *)uap;
	if (sig == SIGUSR1 || sig == SIGUSR2)
		sig_num++;
}

void	giveme_sig(struct sigaction *act)
{
	act->sa_sigaction = &serv_act;
	act->sa_flags = SA_SIGINFO;
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

void	send_sym(char sym, int ppid)
{
	int	res;
	int	mid;
	int	count;

	res = 128;
	count = 7;
	while (res)
	{
		mid = ((res & sym) >> count);
		if (mid == 0)
		{
			if (kill(ppid, SIGUSR1) == -1)
				stop_prog();
			pause();
		}
		else
		{
			if (kill(ppid, SIGUSR2) == -1)
				stop_prog();
			pause();
		}		
		usleep(130);
		count--;
		res = res >> 1;
	}
}

int	read_and_send(char *str, pid_t ppid)
{
	while (*str)
	{
		send_sym(*str, ppid);
		str++;
	}
	send_sym('\n', ppid);
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	giveme_sig(&act);
	if (argc == 3)
		read_and_send(argv[2], ft_atoi(argv[1]));
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}
