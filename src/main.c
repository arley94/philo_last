/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:52:32 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/14 22:39:30 by acoto-gu         ###   ########.fr       */
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
	if (ft_init_forks(&forks_mutexes, app_data.n_philosophers) != 0)
		ft_error("Error creating mutex for forks\n");
	if (ft_init_philos(&philos, forks_mutexes, &app_data) != 0)
		ft_error("Error initializing philos\n");
	ft_manage_threads(philos);
	return (0);
}
