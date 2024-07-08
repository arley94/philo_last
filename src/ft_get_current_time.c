/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 08:23:06 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 08:23:06 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
