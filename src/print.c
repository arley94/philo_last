/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:04:13 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/10 19:54:19 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stdio.h>

void	ft_print_msg(char *str, t_philo *philo)
{
	t_app_data	*data;

	data = philo->app_data;
	pthread_mutex_lock(&data->write_mtx);
	if (!ft_is_finish(philo))
		printf("%zu %d %s", ft_get_current_time()
			- data->start_time, philo->id, str);
	pthread_mutex_unlock(&data->write_mtx);
}
