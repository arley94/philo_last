/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 06:09:58 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 06:09:58 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
	this function checks if the character is \t \n \v \f \c 
*/
static int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	while ((ft_isspace(nptr[i])) && nptr[i])
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(number * sign));
}
