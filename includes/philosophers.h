/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 06:11:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024-07-08 06:11:02 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_str_is_number(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_error(const char *str);
void	ft_check_args(int argc, char const *argv[], t_app_data *app_data);

size_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);

void	ft_init_app_data(t_app_data *app_data);
int		ft_init_forks(pthread_mutex_t **forks_mutexes, int n_philos);
int		ft_init_philos(t_philo **philos, pthread_mutex_t *forks_mutexes,
			const t_app_data *app_data);

void	ft_print_msg(char *str, t_philo *philo);

typedef struct s_app_data
{
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_to_eat;
	size_t			start_time;
	//size_t			finish_thread;
	pthread_mutex_t	write_mtx;
	pthread_mutex_t	finish_mtx;
}	t_app_data;

typedef struct s_philo
{
	int				id;
	pthread_t		t;
	size_t			last_eat_time;
	size_t			eat_count;
	pthread_mutex_t	*fork_l_mtx;
	pthread_mutex_t	*fork_r_mtx;
	pthread_mutex_t	last_eat_time_mtx;
	//pthread_mutex_t	eat_count_mtx;
	t_app_data		*app_data;
}	t_philo;
