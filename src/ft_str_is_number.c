/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 06:14:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 06:14:02 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_str_is_number(const char *str)
{
	if (*str == '\0')
		return (0);
	while (str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
