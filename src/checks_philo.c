/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:40 by pcamaren          #+#    #+#             */
/*   Updated: 2022/06/25 16:54:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_all_ate(t_philo *philo)
{
	int	total_eat;

	pthread_mutex_lock(&philo->_total_eat);
	total_eat = philo->total_eat;
	pthread_mutex_unlock(&philo->_total_eat);
	pthread_mutex_lock(&philo->_meal_count);
	if (philo->meal_count == total_eat)
	{
		pthread_mutex_unlock(&philo->_meal_count);
		return (1);
	}
	pthread_mutex_unlock(&philo->_meal_count);
	return (0);
}

int	check_fork_id(t_fork *fork, t_philo *philo)
{
	int	id_philo;

	pthread_mutex_lock(&philo->_id);
	id_philo = philo->id;
	pthread_mutex_unlock(&philo->_id);
	pthread_mutex_lock(&fork->_id_pf);
	if (fork->id_pf == id_philo)
	{
		pthread_mutex_unlock(&fork->_id_pf);
		return (1);
	}
	pthread_mutex_unlock(&fork->_id_pf);
	return (0);
}
