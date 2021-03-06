/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_mutex(t_param *param)
{
	int		i;

	i = 0;
	while (i < param->num_philo)
	{
		param->philo[i].time_init = current_time();
		param->philo[i].time_toeat = param->t_eat;
		param->philo[i].time_tosleep = param->t_sleep;
		param->philo[i].time_todie = param->t_die;
		if (pthread_mutex_init(&param->philo[i]._l_meal, NULL))
			return ;
		if (pthread_mutex_init(&param->philo[i]._full, NULL))
			return ;
		if (pthread_mutex_init(&param->philo[i]._id, NULL))
			return ;
		if (pthread_mutex_init(&param->philo[i]._meal_count, NULL))
			return ;
		if (pthread_mutex_init(&param->philo[i]._total_eat, NULL))
			return ;
		i++;
	}
}

void	philos_setup(t_param *param)
{
	int	i;

	i = 0;
	param->philo = malloc(sizeof(t_philo) * param->num_philo);
	if (!param->philo)
		return ;
	while (i < param->num_philo)
	{
		param->philo[i].id = i + 1;
		param->philo[i].total_philo = param->num_philo;
		param->philo[i].l_meal = current_time();
		param->philo[i].full = 0;
		param->philo[i].meal_count = 0;
		param->philo[i].total_eat = param->num_eat;
		param->philo[i].left_f = &param->forks[i];
		if (i < param->num_philo - 1)
			param->philo[i].right_f = &param->forks[i + 1];
		else
			param->philo[i].right_f = &param->forks[0];
		param->philo[i].params = param;
		i++;
	}
	philo_mutex(param);
}

void	philo_thread(t_param *param, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < param->num_philo)
	{
		pthread_create(&philos[i], NULL, func, &(param->philo[i]));
		i = i + 2;
	}
	i = 1;
	while (i < param->num_philo)
	{
		pthread_create(&philos[i], NULL, func, &(param->philo[i]));
		i = i + 2;
	}
}

static void	destroy_mutexes(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->num_philo)
	{
		pthread_mutex_destroy(&(param->forks[i].fork));
		pthread_mutex_destroy(&(param->forks[i]._id_pf));
	}
	pthread_mutex_destroy(&(param->_num_eat));
	pthread_mutex_destroy(&(param->time_die));
	pthread_mutex_destroy(&(param->_all_ate));
	pthread_mutex_destroy(&(param->_died));
	pthread_mutex_destroy(&(param->printer));
	pthread_mutex_destroy(&(param->meal_check));
	i = -1;
	while (++i < param->num_philo)
	{
		pthread_mutex_destroy(&(param->philo[i]._id));
		pthread_mutex_destroy(&(param->philo[i]._l_meal));
		pthread_mutex_destroy(&(param->philo[i]._total_eat));
		pthread_mutex_destroy(&(param->philo[i]._full));
		pthread_mutex_destroy(&(param->philo[i]._meal_count));
	}
}

int	init_philo(t_param *param)
{
	int			i;
	pthread_t	*philos;

	philos = malloc(sizeof(pthread_t) * param->num_philo);
	if (!philos)
		return (-1);
	philos_setup(param);
	philo_thread(param, philos);
	check_dead_full(param);
	i = 0;
	while (i < param->num_philo)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	destroy_mutexes(param);
	free(philos);
	free(param->philo);
	free(param->forks);
	return (0);
}
