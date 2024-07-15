/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-15 07:23:57 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-15 07:23:57 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_destroy_nmutex(pthread_mutex_t *mutex_array, int n)
{
	while (n > 0)
	{
		pthread_mutex_destroy(mutex_array + (n - 1));
		n--;
	}
}

void	ft_clean_all(t_app_data *app_data, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&(app_data->write_mtx));
	pthread_mutex_destroy(&(app_data->finish_mtx));

	ft_destroy_nmutex(app_data->forks_mutexes, app_data->n_philosophers);
	free(app_data->forks_mutexes);
	i = 0;
	while (i < app_data->n_philosophers)
	{
		pthread_mutex_destroy(&(philos + i)->eat_mtx);
		i++;
	}
	free(philos);
}

