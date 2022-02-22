/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:25:48 by vellie            #+#    #+#             */
/*   Updated: 2021/09/23 16:26:48 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	puuuut(char c, long int n)
{
	if (n)
	{
		puuuut(c, n / 10);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int n)
{
	long int	num;
	char		c;

	num = n;
	c = 0;
	if (n == 0)
		write(1, "0", 1);
	puuuut(c, num);
	write(1, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	result(char *str)
{
	int			res;
	long long	max;
	int			size;
	int			count;

	res = 0;
	max = 0;
	count = 0;
	size = ft_strlen(str);
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		max = max * 10 + *str - 48;
		str++;
		count++;
		if ((*str >= 48 && *str <= 57) && (max * 10 + *str) < 0)
			return (-1);
	}
	if (size != count)
	{
		write(1, "PID ERROR\n", 10);
		exit(0);
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int	znak;
	int	res;

	znak = 1;
	res = result(str);
	if (res == -1)
	{
		if (znak == 1)
			return (-1);
		else
			return (0);
	}
	return (res * znak);
}
