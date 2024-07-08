/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 06:32:36 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 06:32:36 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0)
	{
		write(fd, s, len);
	}
}
