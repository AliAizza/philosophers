/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/19 00:28:59 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_thread(t_philo *philo)
{
	while (1)
	{
		if (philo->index == 1)
		{
			pthread_mutex_lock(&philo->forks[0]);
			printf("%dms %d has taken a fork",philo->time, philo->index);
			pthread_mutex_lock(&philo->forks[philo->number - 1]);
			printf("%dms %d has taken a fork",philo->time, philo->index);
		}
		else
		{
			pthread_mutex_lock(&philo->forks[philo->index - 1]);
			printf("%dms %d has taken a fork",philo->time, philo->index);
			pthread_mutex_lock(&philo->forks[philo->index - 2]);
			printf("%dms %d has taken a fork",philo->time, philo->index);
		}
	}
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
    int             i;
	int				s;

	s = ft_atoi(argv[1]);
	i = 0;
	while (i < s)
	{
		pthread_join(philo[i].philosopher, NULL);
		philo[i].index = i + 1;
	}
	i = 0;
	while (i < s)
	{
		philo[i].number = i;
		philo[i++].forks = ft_init_forks(philo[0].number);
	}
	i = 0;
	while (i < s)
		pthread_create(&philo[i++].philosopher, NULL, &ft_thread, &philo[i]);
}
