/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:14:46 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/17 00:18:26 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_eating(int p, int t, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	printf("%dms %d is eating\n", t, p);
	pthread_mutex_unlock(&mutex);
}

void	ft_sleeping(int p, int t, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	printf("%dms %d is sleeping\n", t, p);
	pthread_mutex_unlock(&mutex);
}

void	ft_thinking(int p, int t, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	printf("%dms %d is thinking\n", t, p);
	pthread_mutex_unlock(&mutex);
}

void	ft_death(int p, int t, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	printf("%dms %d died\n", t, p);
}
