/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:38:40 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/28 23:59:25 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_time() - philo->last_eat >= philo->time_to_die)
		{
			sem_wait(philo->msg);
			printf("%ld %d died\n", (ft_time() - philo->first_time) \
			, philo->index);
			exit(0);
		}
		usleep(500);
	}
	return (0);
}

void	sumulate(t_philo *philo)
{
	pthread_t	t;

	pthread_create(&t, NULL, &ft_checker, philo);
	while (1)
	{
		sem_wait(philo->forks);
		ft_takefork(philo);
		sem_wait(philo->forks);
		ft_takefork(philo);
		ft_eating(philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
}

int	main(int argc, char **argv)
{
	int		status;
	int		num;
	t_philo	*philo;
	int		i;

	if (!ft_check_args(argc, argv))
	{
		printf("INVALID ARGUMENT!\n");
		return (1);
	}
	num = ft_atoi(argv[1]);
	philo = malloc(num * sizeof(t_philo));
	ft_init_philos(philo, argv, argc, num);
	i = 0;
	while (i < num)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 0)
		{
			ft_kill(philo);
			exit(0);
		}
		i++;
	}
	return (0);
}
