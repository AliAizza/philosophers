/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:14:46 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 04:41:28 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%d %d is eating\n", philo->time / 1000, philo->index);
	pthread_mutex_unlock(&philo->mutex);
	
}

void	ft_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%d %d is sleeping\n", philo->time / 1000 ,philo->index);
	pthread_mutex_unlock(&philo->mutex);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%d %d is thinking\n", philo->time / 1000, philo->index);
	pthread_mutex_unlock(&philo->mutex);
}

void	ft_takefork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%d %d has taken a fork", philo->time / 1000, philo->index);
	pthread_mutex_unlock(&philo->mutex);
}

void	ft_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%d %d died\n", philo->time / 1000, philo->index);
}
