/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 09:40:55 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 09:40:55 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_philo_threads(t_philo *philos,
			void *(*philo_routine)(void *arg))
{
	t_philo			*philo;
	size_t			n_philos;
	size_t			i;

	n_philos = philos->app_data->n_philosophers;
	i = 0;
	while (i < n_philos)
	{
		philo = philos + i;
		pthread_create(&(philo->t), NULL, philo_routine, (void *)philo);
		i++;
	}
}

void	ft_start_threads(t_philo *philos)
{
	//pthread_t		deads_monitor;
	//pthread_t		all_eats_monitor;

	//init_monitor_thread(&deads_monitor, deads_monitor_routine, filo_array);
	//init_monitor_thread(&all_eats_monitor, all_eats_monitor_routine, filo_array);
	init_philo_threads(filo_array, philo_routine);
	pthread_join(deads_monitor, NULL);
	//pthread_join(all_eats_monitor, NULL);
	printf("dead monitor end\n");
	join_threads(filo_array);
	printf("all philos end\n");

}