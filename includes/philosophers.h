/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:11:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/07/11 12:00:13 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

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
	int				finish;
	pthread_mutex_t	*forks_mutexes;
}	t_app_data;

typedef struct s_philo
{
	int				id;
	pthread_t		t;
	size_t			last_eat_time;
	int				eat_count;
	pthread_mutex_t	*fork_l_mtx;
	pthread_mutex_t	*fork_r_mtx;
	pthread_mutex_t	eat_mtx;
	int				is_eating;
	//pthread_mutex_t	eat_count_mtx;
	t_app_data		*app_data;
}	t_philo;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_str_is_number(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_error(const char *str);
void	ft_check_args(int argc, char const *argv[], t_app_data *app_data);

int		ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);

void	ft_init_app_data(t_app_data *app_data);
int		ft_init_forks(pthread_mutex_t **forks_mutexes, int n_philos);
int		ft_init_philos(t_philo **philos, pthread_mutex_t *forks_mutexes,
			t_app_data *app_data);

void	ft_print_msg(char *str, t_philo *philo);

int		check_if_dead(t_philo *philos);
int		check_if_all_ate(t_philo *philos);
void	*philo_routine(void *arg);
void	*monitor_routine(void *pointer);
int		ft_is_finish(t_philo *philo);

void	ft_eat(t_philo *philo, pthread_mutex_t *fork_one,
			pthread_mutex_t *fork_two);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

int		ft_manage_threads(t_philo *philos);

void	ft_destroy_nmutex(pthread_mutex_t *mutex_array, int n);
void	ft_clean_all(t_app_data *app_data, t_philo *philos);