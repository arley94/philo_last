/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:49:21 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/12 18:16:15 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_is_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->app_data->finish_mtx);
	if (philo->app_data->finish == 1)
		return (pthread_mutex_unlock(&philo->app_data->finish_mtx), 1);
	pthread_mutex_unlock(&philo->app_data->finish_mtx);
	return (0);
}

int	ft_philo_is_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mtx);
	if (philo->eat_count == philo->app_data->n_times_to_eat)
		return (pthread_mutex_unlock(&philo->eat_mtx), 1);
	pthread_mutex_unlock(&philo->eat_mtx);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!ft_is_finish(philo) && !ft_philo_is_full(philo))
	{
		if (philo->id % 2)
			ft_eat(philo, philo->fork_l_mtx, philo->fork_r_mtx);
		else
			ft_eat(philo, philo->fork_r_mtx, philo->fork_l_mtx);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	philosopher_dead(t_philo *philo)
{
	int	time_since_last_meal;
	int	is_eating;
	int	last_eat_time;

	pthread_mutex_lock(&(philo->eat_mtx));
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&(philo->eat_mtx));
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

void	*monitor_routine(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}