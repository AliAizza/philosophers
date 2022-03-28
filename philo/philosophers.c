/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 03:30:09 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checker(t_philo *philo)
{
	int	i;
	int	x;

	x = 0;
	while (x < philo->number || philo->total_meals == -1)
	{
		i = -1;
		x = 0;
		while (++i < philo->number)
		{
			if (ft_time() - philo[i].last_eat >= philo->time_to_die * 1000)
			{
				ft_death(philo + i);
				return (0);
			}
			if (philo[i].number_of_meals >= philo->total_meals)
				x++;
		}
	}
	return (0);
}

void	*ft_thread(void *x)
{
	t_philo	*philo;

	philo = (t_philo *)x;
	philo->last_eat = ft_time();
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->index]);
		ft_takefork(philo);
		pthread_mutex_lock(&philo->forks[philo->index + 1 % philo->number]);
		ft_takefork(philo);
		philo->last_eat = ft_time();
		ft_eating(philo);
		pthread_mutex_unlock(&philo->forks[philo->index]);
		pthread_mutex_unlock(&philo->forks[philo->index + 1 % philo->number]);
		if (philo->total_meals != -1)
			philo->number_of_meals++;
		if (philo->number_of_meals == philo->total_meals)
			break ;
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (0);
}

void	ft_create_threads(t_philo *philo, int num)
{
	int			i;
	pthread_t	*th;

	th = malloc(num * sizeof(pthread_t));
	i = 0;
	while (i < num)
	{
		pthread_create(th + i, NULL, &ft_thread, &philo[i]);
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < num)
	{
		pthread_create(th + i, NULL, &ft_thread, &philo[i]);
		i += 2;
	}
	free(th);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	long long	x;

	if (!ft_check_args(argc, argv))
	{
		printf("INVALID ARGUMENT!\n");
		return (1);
	}
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	x = ft_time();
	ft_init_philos(philo, x, argc, argv);
	ft_create_threads(philo, ft_atoi(argv[1]));
	free(philo->forks);
	free(philo->mutex);
	free(philo);
	if (!ft_checker(philo))
		return (1);
	return (0);
}
