/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:25:17 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/21 09:26:33 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*ft_init_forks(int x)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(x * sizeof(pthread_mutex_t));
	i = 0;
	while (i < x)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

void	ft_init_philos(t_philo *philo, long long x, int argc, char **argv)
{
	int				i;
	pthread_mutex_t	*m;
	pthread_mutex_t	*f;

	m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m, NULL);
	f = ft_init_forks(ft_atoi(argv[1]));
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].mutex = m;
		philo[i].number_of_meals = 0;
		philo[i].number = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].eating_time = ft_atoi(argv[3]);
		philo[i].sleeping_time = ft_atoi(argv[4]);
		philo[i].total_meals = -1;
		if (argc == 6)
			philo[i].total_meals = ft_atoi(argv[5]);
		philo[i].index = i;
		philo[i].last_eat = ft_time();
		philo[i].first_time = x;
		philo[i++].forks = f;
	}
}
