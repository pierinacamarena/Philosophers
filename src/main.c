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

void *func(void *philo_void)
{
	t_philo *philo;

	philo = (t_philo *)philo_void;
	while (!philo->full && !philo->dead)
	{
		eat(philo);
	}
	return (NULL);
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

int	init_philo(t_param *param)
{
	int i;
	pthread_t *philos;

	philos = malloc(sizeof(pthread_t) * param->num_philo);
	if (!philos)
		return (-1);
	philos_setup(param);
	philo_thread(param, philos);
	i = 0;
    while (i < param->num_philo)
    {
        pthread_join(philos[i], NULL);
		i++;
    }
	return (0);
}

int	main(int ac, char **av)
{
	int	error;
	t_param param;
	
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
