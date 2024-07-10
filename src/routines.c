/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:49:21 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/10 10:22:46 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
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