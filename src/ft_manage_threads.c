/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:04:05 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/09 10:12:53 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_philo_threads(t_philo *philos,
			void *(*philo_routine)(void *arg))
{
	t_philo			*philo;
	t_app_data		*data;
	int			i;

	data = philos[0].app_data;
	i = 0;
	while (i < data->n_philosophers)
	{
		philo = philos + i;
		pthread_create(&(philo->t), NULL, philo_routine, (void *)philo);
		i++;
	}
}

void	join_threads(t_philo *philos)
{
	t_philo		*philo;
	t_app_data	*data;
	int			i;

	data = philos[0].app_data;
	i = 0;
	while (i < data->n_philosophers)
	{
		philo = philos + i;
		pthread_join(philo->t, NULL);
		i++;
	}
}

void	ft_manage_threads(t_philo *philos)
{
	//pthread_t		deads_monitor;
	//pthread_t		all_eats_monitor;

	//init_monitor_thread(&deads_monitor, deads_monitor_routine, filo_array);
	//init_monitor_thread(&all_eats_monitor, all_eats_monitor_routine, filo_array);
	init_philo_threads(philos, philo_routine);
	//pthread_join(deads_monitor, NULL);
	//pthread_join(all_eats_monitor, NULL);
	//printf("dead monitor end\n");
	join_threads(philos);
	//printf("all philos end\n");

}