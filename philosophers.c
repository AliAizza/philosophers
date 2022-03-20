/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 08:33:30 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check(t_philo *philo)
{
	int			finish_eat;
	int			i;

	i = -1;
	finish_eat = 0;
	while (finish_eat != philo->number)
	{
		finish_eat = 0;
		i = -1;
		while (++i < philo->number)
		{
			if (philo[i].number_of_meals == philo->total_meals)
				finish_eat++;
			if (ft_time() - philo[i].last_eat >= philo->time_to_die * 1000)
			{
				ft_death(philo);
				exit (0);
			}
		}
	}
}

void	*ft_thread(void *x)
{
	t_philo	*philo;

	philo = (t_philo *)x;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->index]);
		ft_takefork(philo);
		pthread_mutex_lock(&philo->forks[philo->index - 1]);
		ft_takefork(philo);
		ft_eating(philo);
		philo->last_eat = ft_time();
		pthread_mutex_unlock(&philo->forks[philo->index]);
		pthread_mutex_unlock(&philo->forks[philo->index - 1]);
		philo->number_of_meals++;
		if (philo->number_of_meals == philo->total_meals)
			break;
		ft_sleeping(philo);
		ft_thinking(philo);
		usleep(100);
	}
	return (0);
}

pthread_mutex_t	*ft_init_forks(int x)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(x * sizeof(pthread_mutex_t));
	i = 0;
	while(i < x)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

int main(int argc, char **argv)
{
	t_philo	*philo;
    pthread_mutex_t	*m;
	int		i;
	long long	x;

	x = ft_time();
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	philo->philosopher = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
	m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m, NULL);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].mutex = m;
		philo[i].number_of_meals = 0;
		philo[i].number = ft_atoi(argv[1]);;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].eating_time = ft_atoi(argv[3]);
		philo[i].sleeping_time = ft_atoi(argv[4]);
		philo[i].total_meals = -1;
		if (argc == 6)
			philo[i].total_meals = ft_atoi(argv[5]);
		philo[i].index = i + 1;
		philo[i].last_eat = ft_time();
		philo[i].first_time = x;
		philo[i].forks = ft_init_forks(ft_atoi(argv[1]));
		pthread_create(philo->philosopher + i, NULL, &ft_thread, &philo[i]);
		i++;
	}
	ft_check(philo);
}
