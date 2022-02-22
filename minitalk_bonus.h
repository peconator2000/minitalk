/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:42:15 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 16:56:00 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void	ft_putnbr(int n);
void	send_answer(siginfo_t *info);
void	stop_prog(void);

#endif