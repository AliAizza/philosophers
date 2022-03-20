/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:14:46 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 12:02:17 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld %d is eating\n", (ft_time() - philo->first_time) / 1000, philo->index + 1);
	pthread_mutex_unlock(philo->mutex);
	ft_sleep(philo->eating_time);
}

void	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld %d is sleeping\n", (ft_time() - philo->first_time) / 1000, philo->index + 1);
	pthread_mutex_unlock(philo->mutex);
	ft_sleep(philo->sleeping_time);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld %d is thinking\n", (ft_time() - philo->first_time) / 1000, philo->index + 1);
	pthread_mutex_unlock(philo->mutex);
}

void	ft_takefork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld %d has taken a fork\n", (ft_time() - philo->first_time) / 1000, philo->index + 1);
	pthread_mutex_unlock(philo->mutex);
}

void	ft_death(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lld %d died\n", (ft_time() - philo->first_time) / 1000, philo->index + 1);
}
