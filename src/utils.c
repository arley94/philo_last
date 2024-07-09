/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:42:25 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/09 09:46:52 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0)
	{
		write(fd, s, len);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
