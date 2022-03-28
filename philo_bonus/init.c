/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:38:22 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 23:38:26 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	create_procceses(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			sumulate(&(philo[i]));
			exit(0);
		}
		i++;
	}
}

void	init_data(t_philo *philo, char **argv, int argc)
{
	int	dead;

	dead = 0;
	philo->number = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->eating_time = ft_atoi(argv[3]);
	philo->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
		philo->total_meals = ft_atoi(argv[5]);
	philo->number_of_meals = 0;
	philo->dead = &dead;
}

void	ft_init_philos(t_philo *philo, char **argv, int argc, int n)
{
	int		i;
	sem_t	*forks;
	sem_t	*msg;

	sem_unlink("msg");
	sem_unlink("semaphore");
	msg = sem_open("msg", O_CREAT | O_EXCL, 0644, 1);
	if (msg == SEM_FAILED)
		exit(1);
	forks = sem_open("semaphore", O_CREAT | O_EXCL, 0644, n);
	if (forks == SEM_FAILED)
		exit(1);
	i = 0;
	while (i < n)
	{
		init_data(&(philo[i]), argv, argc);
		philo[i].forks = forks;
		philo[i].last_eat = ft_time();
		philo[i].index = i + 1;
		philo[i].msg = msg;
		philo[i].first_time = ft_time();
		philo[i].argc = argc;
		i++;
	}
	create_procceses(philo, n);
}
