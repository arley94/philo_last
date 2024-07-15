/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-15 09:50:16 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-15 09:50:16 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philosopher_dead(t_philo *philo)
{
	int	time_since_last_meal;
	int	is_eating;
	int	last_eat_time;
	int	eat_count;

	eat_count = 0;
	pthread_mutex_lock(&(philo->eat_mtx));
	last_eat_time = philo->last_eat_time;
	eat_count = philo->eat_count;
	pthread_mutex_unlock(&(philo->eat_mtx));
	if (eat_count == philo->app_data->n_times_to_eat)
		return (0);
	time_since_last_meal = ft_get_current_time() - last_eat_time;
	if (time_since_last_meal >= philo->app_data->time_to_die)
	{
		pthread_mutex_lock(&(philo->eat_mtx));
		is_eating = philo->is_eating;
		pthread_mutex_unlock(&(philo->eat_mtx));
		if (is_eating == 0)
			return (1);
	}
	return (0);
}

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].app_data->n_philosophers)
	{
		if (philosopher_dead(&philos[i]))
		{
			ft_print_msg("has died\n", &philos[i]);
			pthread_mutex_lock(&philos->app_data->finish_mtx);
			philos->app_data->finish = 1;
			pthread_mutex_unlock(&philos->app_data->finish_mtx);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].app_data->n_times_to_eat == -1)
		return (0);
	while (i < philos[0].app_data->n_philosophers)
	{
		pthread_mutex_lock(&(philos[i].eat_mtx));
		if (philos[i].eat_count >= philos[i].app_data->n_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(&(philos[i].eat_mtx));
		i++;
	}
	if (finished_eating == philos[0].app_data->n_philosophers)
	{
		pthread_mutex_lock(&(philos[0].app_data->finish_mtx));
		philos->app_data->finish = 1;
		pthread_mutex_unlock(&(philos[0].app_data->finish_mtx));
		return (1);
	}
	return (0);
}
