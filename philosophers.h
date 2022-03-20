/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:26:25 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/20 09:25:19 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_philo
{
    pthread_t		*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex;
	int				total_meals;
	int				number_of_meals;
	int				eating_time;
	int				sleeping_time;
	int				time_to_die;
	int				index;
	int				number;
	long long		first_time;
	long long		time;
	long long		last_eat;
}   t_philo;

void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_takefork(t_philo *philo);
void		ft_death(t_philo *philo);
int			ft_atoi(char *str);
long long	ft_time(void);
void		ft_sleep(long time);
void		ft_check(t_philo *philo);
int			ft_digit_check(char *str);

#endif