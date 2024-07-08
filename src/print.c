/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:04:13 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 08:04:13 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_msg(char *str, t_philo *philo)
{
	t_app_data	*data;

	data = philo->app_data;
	pthread_mutex_lock(&data->write_mtx);
	//if (!end_loop(data))
	printf("%zu %d %s", ft_get_time() - data->start_time, philo->id, str);
	pthread_mutex_unlock(&data->write_mtx);
}
