/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:36:53 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 16:43:22 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		}
		else
		{
			if (kill(ppid, SIGUSR2) == -1)
				stop_prog();
		}		
		usleep(50);
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
	if (argc == 3)
		read_and_send(argv[2], ft_atoi(argv[1]));
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}
