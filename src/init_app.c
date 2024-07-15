/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:39:11 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/12 21:17:59 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_app_data(t_app_data *app_data)
{
	app_data->finish = 0;
	app_data->start_time = ft_get_current_time();
	if (pthread_mutex_init(&app_data->write_mtx, NULL) != 0)
		ft_error("error creating mutex");
	if (pthread_mutex_init(&app_data->finish_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&app_data->write_mtx);
		ft_error("error creating mutex");
	}
}

int	ft_init_forks(pthread_mutex_t **forks_mutexes, int n_philos)
{
	int	i;

	*forks_mutexes = malloc(sizeof(pthread_mutex_t) * n_philos);
	if (!(*forks_mutexes))
		return (1);
	i = 0;
	while (i < n_philos)
	{
		if (pthread_mutex_init(*forks_mutexes + i, NULL) != 0)
		{
			while (--i)
				pthread_mutex_destroy(*forks_mutexes + i);
			free(*forks_mutexes);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_init_philos(t_philo **philos, pthread_mutex_t *forks_mutexes,
		t_app_data *app_data)
{
	int		i;

	*philos = malloc(sizeof(t_philo) * app_data->n_philosophers);
	if (!(*philos))
		return (1);
	i = 0;
	while (i < app_data->n_philosophers)
	{
		((*philos) + i)->id = i + 1;
		((*philos) + i)->eat_count = 0;
		((*philos) + i)->is_eating = 0;
		((*philos) + i)->app_data = app_data;
		((*philos) + i)->last_eat_time = app_data->start_time;
		if (pthread_mutex_init(&(((*philos) + i)->eat_mtx), NULL) != 0)
		{
			while (--i)
				pthread_mutex_destroy(&(((*philos) + i)->eat_mtx));
			return (free(*philos), 1);
		}
		((*philos) + i)->fork_l_mtx = forks_mutexes + i;
		((*philos) + i)->fork_r_mtx = forks_mutexes + ((i + 1)
				% app_data->n_philosophers);
		i++;
	}
	return (0);
}
