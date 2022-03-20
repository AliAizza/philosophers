/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 04:55:59 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		philo->last_eat = (ft_time() - philo->first_time) / 1000;
		pthread_mutex_unlock(&philo->forks[philo->index]);
		pthread_mutex_unlock(&philo->forks[philo->index - 1]);
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
    int		i;
	int		s;

	s = ft_atoi(argv[1]);
	i = 0;
	while (i < s)
	{
		philo[i].number = s;
		philo[i].index = i + 1;
		philo[i].first_time = ft_time();
		philo[i].forks = ft_init_forks(s);
		pthread_create(&philo[i].philosopher, NULL, &ft_thread, &philo[i]);
		i++;
	}

}
