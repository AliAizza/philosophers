/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:24:37 by aaizza            #+#    #+#             */
/*   Updated: 2022/03/17 00:08:10 by aaizza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_thread(void *arg)
{}

int main(int argc, char **argv)
{
    pthread_t		*philosopher;
	pthread_mutex_t	mutex;
    int             i;
	int				s;

	s = ft_atoi(argv[1]);
	i = 0;
	while (i < s)
		pthread_create(&philosopher[i++], NULL, ft_thread, NULL);
	i = 0;
	while (i < s)
		pthread_join(&philosopher[i++], NULL);
	pthread_mutex_init(&mutex, NULL);
}