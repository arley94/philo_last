/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:04:05 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/12 21:43:27 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_philo_threads(t_philo *philos,
			void *(*philo_routine)(void *arg))
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < philos->app_data->n_philosophers)
	{
		philo = philos + i;
		if (pthread_create(&(philo->t), NULL, philo_routine, (void *)philo))
			return (1);
		i++;
	}
	return (0);
}

void	join_threads(t_philo *philos)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < philos->app_data->n_philosophers)
	{
		philo = philos + i;
		pthread_join(philo->t, NULL);
		i++;
	}
}

int	ft_manage_threads(t_philo *philos)
{
	pthread_t		deads_monitor;

	if (pthread_create(&deads_monitor, NULL, monitor_routine, philos) != 0)
		return (1);
	if (init_philo_threads(philos, philo_routine) != 0)
		return (1);
	pthread_join(deads_monitor, NULL);
	join_threads(philos);
	return (0);
}
