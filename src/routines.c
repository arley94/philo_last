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
	if (philo->app_data->n_philosophers == 1)
	{
		pthread_mutex_unlock(philo->fork_l_mtx);
		ft_print_msg("has taken a fork\n", philo);
		ft_usleep(philo->app_data->time_to_die);
		pthread_mutex_unlock(philo->fork_l_mtx);
		return (NULL);
	}
	if ((philo->id % 2) == 0)
		ft_usleep(philo->app_data->time_to_eat / 2);
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

void	*monitor_routine(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (pointer);
}
