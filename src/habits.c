/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:53:10 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/12 07:21:02 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_eat(t_philo *philo, pthread_mutex_t *fork_one,
	pthread_mutex_t *fork_two)
{
	t_app_data	*app_data;
	int			tmp_time;

	app_data = philo->app_data;
	pthread_mutex_lock(fork_one);
	ft_print_msg("has taken a fork\n", philo);
	pthread_mutex_lock(fork_two);
	ft_print_msg("has taken a fork\n", philo);
	pthread_mutex_lock(&philo->eat_mtx);
	philo->is_eating = 1;
	tmp_time = ft_get_current_time();
	philo->last_eat_time = tmp_time;
	pthread_mutex_unlock(&philo->eat_mtx);
	ft_print_msg("is eating\n", philo);
	ft_usleep(app_data->time_to_eat);
	pthread_mutex_lock(&philo->eat_mtx);
	philo->is_eating = 0;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_mtx);
	pthread_mutex_unlock(fork_one);
	pthread_mutex_unlock(fork_two);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_msg("is sleeping\n", philo);
	ft_usleep(philo->app_data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print_msg("is thinking\n", philo);
	if (philo->app_data->time_to_sleep <= philo->app_data->time_to_eat)
		ft_usleep((philo->app_data->time_to_eat + 5)
			- philo->app_data->time_to_sleep);
}
