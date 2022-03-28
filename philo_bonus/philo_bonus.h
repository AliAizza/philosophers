/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:38:34 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 23:38:36 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

typedef struct s_philo {
	pid_t		pid;
	int			index;
	int			number;
	int			eating_time;
	int			sleeping_time;
	int			time_to_die;
	int			total_meals;
	int			number_of_meals;
	sem_t		*forks;
	sem_t		*msg;
	long int	first_time;
	int long	last_eat;
	int			argc;
	int			*dead;
}	t_philo;

void		sumulate(t_philo *philo);
int			ft_atoi(char *str);
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_takefork(t_philo *philo);
long int	ft_time(void);
void		ft_sleep(long delay);
void		fill_data(t_philo *philo, char **argv, \
			pthread_mutex_t *forks, int i);
void		init_data(t_philo *philo, char **argv, int argc);
void		init_semaphore(t_philo *philo, int i);
void		ft_init_philos(t_philo *philo, char **argv, int argc, \
			int n);
void		ft_kill(t_philo *philo);
int			ft_check_args(int argc, char **argv);

#endif