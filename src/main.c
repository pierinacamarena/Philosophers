/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	one_philo(t_philo *philo)
{
	if (philo->total_philo == 1)
	{
		pthread_mutex_lock(&(philo->left_f->fork));
		locked_print(philo, 1);
		pthread_mutex_unlock(&(philo->left_f->fork));
		my_sleep(philo, philo->params->t_die);
		usleep(500);
		pthread_mutex_lock(&(philo->params->_died));
		philo->params->died = 1;
		pthread_mutex_unlock(&(philo->params->_died));
	}
}

void	*func(void *philo_void)
{
	t_philo	*philo;
	t_param	*param;

	philo = (t_philo *)philo_void;
	param = philo->params;
	one_philo(philo);
	if (philo->id % 2)
		usleep(15000);
	while (!check_death(param) || !check_full(philo))
	{
		if (check_full(philo) || eat(philo) == 1)
			break ;
		if (check_all_ate(philo))
		{
			pthread_mutex_lock(&philo->_full);
			philo->full = 2;
			pthread_mutex_unlock(&philo->_full);
		}
		if (check_death(param) || check_full(philo) || philo_sleep(philo) == 1)
			break ;
		if (!check_death(param))
			locked_print(philo, 4);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int		error;
	t_param	param;

	if (ac < 5 || ac > 6)
	{
		error_arg();
		exit(1);
	}
	error = arg_parsing(ac, av, &param);
	if (error == 1)
	{
		error_parsing();
		exit (1);
	}
	init_philo(&param);
	return (0);
}
