/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 12:06:14 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check(t_philo *philo)
{
	int	meals;
	int	i;

	meals = 0;
	while (meals != philo->number)
	{
		meals = 0;
		i = 0;
		while (i < philo->number)
		{
			if (philo[i].number_of_meals == philo->total_meals)
				meals++;
			if (ft_time() - philo[i].last_eat >= philo->time_to_die * 1000)
			{
				ft_death(philo);
				exit (0);
			}
			i++;
		}
	}
}

void	ft_checker(t_philo *philo)
{
	while (1)
	{
		if (ft_time() - philo->last_eat >= philo->time_to_die * 1000)
		{
			ft_death(philo);
			exit(0);
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
		pthread_mutex_lock(&philo->forks[philo->index + 1 % philo->number]);
		ft_takefork(philo);
		philo->last_eat = ft_time();
		ft_eating(philo);
		pthread_mutex_unlock(&philo->forks[philo->index]);
		pthread_mutex_unlock(&philo->forks[philo->index + 1]);
		if (philo->total_meals != -1)
			philo->number_of_meals++;
		if (philo->number_of_meals == philo->total_meals)
			break ;
		ft_sleeping(philo);
		ft_thinking(philo);
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
	int	j;

	j = argc;
	while (argc > 1)
	{
		if (!ft_digit_check(argv[argc - 1]))
		{
			write(1, "INVALID ARGUMENT!\n", 19);
			return (1);
		}
		argc--;
	}
	philo = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	philo->philosopher = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
	m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m, NULL);
	i = 0;
	x = ft_time();
	while (i < ft_atoi(argv[1]))
	{
		philo[i].mutex = m;
		philo[i].number_of_meals = 0;
		philo[i].number = ft_atoi(argv[1]);;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].eating_time = ft_atoi(argv[3]);
		philo[i].sleeping_time = ft_atoi(argv[4]);
		philo[i].total_meals = -1;
		if (j == 6)
			philo[i].total_meals = ft_atoi(argv[5]);
		philo[i].index = i;
		philo[i].last_eat = ft_time();
		philo[i].first_time = x;
		philo[i].forks = ft_init_forks(ft_atoi(argv[1]));
		pthread_create(&philo->philosopher[i], NULL, &ft_thread, &philo[i]);
		i++;
		usleep(100);
	}
	// while (1)
	// {
	// 	i = 0;
	// 	while (i < ft_atoi(argv[1]))
	// 	{
	// 		if ((ft_time() - philo[i].last_eat) / 1000 >= philo->time_to_die)
	// 		{
	// 			ft_death(philo);
	// 			exit(0);
	// 		}
	// 		i++;
	// 	}
	// }
	ft_check(philo);
	// i = 0;
	// while (i < ft_atoi(argv[1]))
	// {
	// 	pthread_join(*(philo->philosopher + i), NULL);
	// 	i++;
	// }
}
