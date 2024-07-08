/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 09:39:11 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 09:39:11 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_app_data(t_app_data *app_data)
{
	app_data->start_time = ft_get_current_time();
	pthread_mutex_init(&app_data->write_mtx, NULL);
	pthread_mutex_init(&app_data->finish_mtx, NULL);
}

int	ft_init_forks(pthread_mutex_t **forks_mutexes, int n_philos)
{
	size_t	i;

	*forks_mutexes = malloc(sizeof(pthread_mutex_t) * n_philos);
	if (!forks_mutexes)
		return (1);
	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_init(*forks_mutexes + i, NULL);
		i++;
	}
	return (0);
}

int	ft_init_philos(t_philo **philos, pthread_mutex_t *forks_mutexes,
		const t_app_data *app_data)
{
	size_t	i;
	t_philo	*philo_array;

	philo_array = malloc(sizeof(t_philo) * app_data->n_philosophers);
	*philos = philo_array;
	if (*philos)
		return (1);
	i = 0;
	while (i < app_data->n_philosophers)
	{
		philo_array[i].id = i + 1;
		philo_array[i].app_data = app_data;
		philo_array[i].last_eat_time = app_data->start_time;
		pthread_mutex_init(&(philo_array[i].last_eat_time_mtx), NULL);
		if (philo_array[i].id % 2)
		{
			philo_array[i].fork_l_mtx = forks_mutexes + i;
			philo_array[i].fork_r_mtx = forks_mutexes + ((i + 1)
				% app_data->n_philosophers);
		}
		else
		{
			philo_array[i].fork_r_mtx = forks_mutexes + i;
			philo_array[i].fork_l_mtx = forks_mutexes + ((i + 1)
				% app_data->n_philosophers);
		}
		i++;
	}
	return (0);
}
