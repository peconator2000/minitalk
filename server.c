/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:27:43 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 16:47:11 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static char	sym;
	static int	bit;

	if (sig == SIGUSR1)
	{
		sym = (sym << 1);
		bit++;
	}
	else if (sig == SIGUSR2)
	{
		sym = (sym << 1) + 1;
		bit++;
	}
	if (bit > 7)
	{
		write(1, &sym, 1);
		sym = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int	ppid;

	argv = (void *)argv;
	ppid = getpid();
	ft_putnbr(ppid);
	if (argc != 1)
	{
		write(1, "NOT VALID\n", 10);
		exit(0);
	}
	while (1)
	{
		signal(SIGUSR1, &signal_handler);
		signal(SIGUSR2, &signal_handler);
		pause();
	}
}
