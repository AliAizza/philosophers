/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:55:10 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 08:00:21 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000000) + time.tv_usec);
}

void ft_sleep(long time)
{
	long i;

	i = ft_time();
	while(ft_time() - i < time)
		usleep(20);
}
