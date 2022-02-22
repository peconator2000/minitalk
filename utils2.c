/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:42:35 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 16:56:53 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_answer(siginfo_t *info)
{
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		write(1, "CAN'T SEND MESSAGE\n", 20);
		exit(0);
	}
}

void	stop_prog(void)
{
	write(1, "CAN'T SEND MESSAGE\n", 20);
	exit(0);
}
