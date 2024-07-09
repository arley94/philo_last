/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:52:32 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/09 10:05:59 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char const *argv[])
{
	t_app_data		app_data;
	pthread_mutex_t	*forks_mutexes;
	t_philo			*philos;

	ft_check_args(argc, argv, &app_data);
	ft_init_app_data(&app_data);
	ft_init_forks(&forks_mutexes, app_data.n_philosophers);
	ft_init_philos(&philos, forks_mutexes, &app_data);
	ft_manage_threads(philos);
	return (0);
}
