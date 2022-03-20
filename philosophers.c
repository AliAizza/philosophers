/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 17:39:45 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	socrates(t_philo *philo)
{
	int			i;
	long long	x;
	long long	y;

	while (1)
	{
		i = 0;
		while (i < philo->number)
		{
			y = philo->time_to_die * 1000;
			x = ft_time() - philo->last_eat;
			if (x >= y)
			{
				ft_death(philo);
				exit(0);
			}
			if (philo->number_of_meals >= philo->total_meals && philo->total_meals != -1)
			{
				exit(0);
			}	
			i++;
		}
	}
}

void	ft_check(t_philo *philo)
{
	int	meals;
	int	i;
	long long	time; 

	meals = 0;
	while (meals != philo->number)
	{
		time = ft_time();
		meals = 0;
		i = 0;
		while (i < philo->number)
		{
			if (philo[i].number_of_meals == philo->total_meals)
				meals++;
			if (time - philo[i].last_eat >= philo->time_to_die * 1000)
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
		ft_eating(philo);
		philo->last_eat = ft_time();
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
	pthread_t	*th;
    pthread_mutex_t	*m;
	pthread_mutex_t	*f;
	int		i;
	long long	x;
	int	j;
	int	die = ft_atoi(argv[2]);
	int	eat = ft_atoi(argv[3]);
	int	sleep = ft_atoi(argv[4]);
	int	num = ft_atoi(argv[1]);
	int	total;
	if	(argc == 6)
		total = ft_atoi(argv[5]);

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
	philo = malloc(num * sizeof(t_philo));
	th = malloc(num * sizeof(pthread_t));
	m = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m, NULL);
	f = ft_init_forks(num);
	i = 0;
	x = ft_time();
	while (i < num)
	{
		philo[i].mutex = m;
		philo[i].number_of_meals = 0;
		philo[i].number = num;
		philo[i].time_to_die = die;
		philo[i].eating_time = eat;
		philo[i].sleeping_time = sleep;
		philo[i].total_meals = -1;
		if (j == 6)
			philo[i].total_meals = total;
		philo[i].index = i;
		philo[i].last_eat = ft_time();
		philo[i].first_time = x;
		philo[i].forks = f;
		pthread_create(th + i, NULL, &ft_thread, &philo[i]);
		i++;
		//usleep(500);
	}
	// i = 0;
	// while (i < num)
	// {
	// 	pthread_create(th + i, NULL, &ft_thread, &philo[i]);
	// 	i += 2;
	// }
	//usleep(1000);
	// i = 1;
	// while (i < num)
	// {
	// 	pthread_create(th + i, NULL, &ft_thread, &philo[i]);
	// 	i += 2;
	// }
	//socrates(philo);
	//ft_check(philo);
	while (1)
	{
		i = 0;
		while (i < ft_atoi(argv[1]))
		{
			if ((ft_time() - philo[i].last_eat) / 1000 >= philo->time_to_die)
			{
				ft_death(philo);
				exit(0);
			}
			i++;
		}
	}
	// i = 0;
	// while (i < ft_atoi(argv[1]))
	// {
	// 	pthread_join(*(philo->philosopher + i), NULL);
	// 	i++;
	// }
}
