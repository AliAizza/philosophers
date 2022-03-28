/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:38:47 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 23:38:50 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000000) + time.tv_usec) / 1000);
}

void	ft_sleep(long time)
{
	long	i;

	i = ft_time();
	while (ft_time() - i <= time)
		usleep(500);
}

void	ft_kill(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

int	ft_digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_digit_check(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
