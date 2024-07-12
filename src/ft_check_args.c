/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:52:09 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/11 13:58:56 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_number(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_initialize_app_data(int argc, char const *argv[],
			t_app_data *app_data)
{
	app_data->n_philosophers = ft_atoi(argv[1]);
	app_data->time_to_die = ft_atoi(argv[2]);
	app_data->time_to_eat = ft_atoi(argv[3]);
	app_data->time_to_sleep = ft_atoi(argv[4]);
	app_data->n_times_to_eat = -1;
	if (argc == 6)
		app_data->n_times_to_eat = ft_atoi(argv[5]);
}

void	ft_check_arg_ranges(const t_app_data *app_data)
{
	if (app_data->n_philosophers < 1)
		ft_error("Must be at least 1 philosophers");
	if (app_data->time_to_die < 0)
		ft_error("time_to_die must be >= 0 ");
	if (app_data->time_to_eat < 0)
		ft_error("time_to_eat must be >= 0 ");
	if (app_data->time_to_sleep < 0)
		ft_error("time_to_sleep must be >= 0 ");
	if (app_data->n_times_to_eat < 0 && app_data->n_times_to_eat != -1)
		ft_error("n_times_to_eat must be >= 0 ");
}

void	ft_check_args(int argc, char const *argv[], t_app_data *app_data)
{
	if (argc >= 5 && argc <= 6)
	{
		if (!ft_str_is_number(argv[1]) || !ft_str_is_number(argv[2])
			|| !ft_str_is_number(argv[3]) || !ft_str_is_number(argv[4]))
			ft_error("Arguments must be numbers\n");
		if (argc == 6 && !ft_str_is_number(argv[5]))
			ft_error("Arguments must be numbers\n");
		ft_initialize_app_data(argc, argv, app_data);
		ft_check_arg_ranges(app_data);
	}
	else
		ft_error("Wrong number of arguments\n");

}
