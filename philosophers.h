/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:26:25 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/19 00:13:17 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_philo
{
    pthread_t		philosopher;
	pthread_mutex_t	*forks;
	int				index;
	int				number;
	int				first_time;
	int				time;
}   t_philo;

void    ft_eating(int p, int t, pthread_mutex_t mutex);
void	ft_sleeping(int p, int t, pthread_mutex_t mutex);
void	ft_thinking(int p, int t, pthread_mutex_t mutex);
void	ft_death(int p, int t, pthread_mutex_t mutex);
int	    ft_atoi(char *str);

#endif