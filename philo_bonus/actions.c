/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:38:16 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 23:38:18 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eating(t_philo *philo)
{
	sem_wait(philo->msg);
	printf("%ld %d is eating\n", \
		(ft_time() - philo->first_time), philo->index);
	philo->last_eat = ft_time();
	sem_post(philo->msg);
	ft_sleep(philo->eating_time);
	if (philo->argc == 6)
	{
		philo->number_of_meals += 1;
		if (philo->number_of_meals == philo->total_meals)
		{
			sem_post(philo->forks);
			sem_post(philo->forks);
			exit(2);
		}
	}
}

void	ft_sleeping(t_philo *philo)
{
	sem_wait(philo->msg);
	printf("%ld %d is sleeping\n", \
		(ft_time() - philo->first_time), philo->index);
	sem_post(philo->msg);
	ft_sleep(philo->sleeping_time);
}

void	ft_thinking(t_philo *philo)
{
	sem_wait(philo->msg);
	printf("%ld %d is thinking\n", \
		(ft_time() - philo->first_time), philo->index);
	sem_post(philo->msg);
}

void	ft_takefork(t_philo *philo)
{
	sem_wait(philo->msg);
	printf("%ld %d has taken a fork\n", \
		(ft_time() - philo->first_time), philo->index);
	sem_post(philo->msg);
}
