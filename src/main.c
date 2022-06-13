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
	//int		i;

	//i = 0;
	philo = (t_philo *)philo_void;
	while (philo->full != 1 && philo->dead == 0)
	{
		eat(philo);
		if (philo->total_eat > 0 && philo->meal_count == philo->total_eat)
		{
			philo->full = 2;
		}
		printf("%lldms philo %d is sleeping\n", timestamp() - philo->time_init, philo->id);
  	  	usleep(philo->time_tosleep);
    	printf("%lldms philo %d is thinking\n", timestamp() - philo->time_init, philo->id);
		//i++;
	}
/*	if (philo->total_eat == 0)
	{
		while (!philo->full && philo->dead == 0)
		{
			eat(philo);
			printf("%lldms philo %d is sleeping\n", timestamp() - philo->time_init, philo->id);
	  	  	usleep(philo->time_tosleep);
	    	printf("%lldms philo %d is thinking\n", timestamp() - philo->time_init, philo->id);
			i++;
		}
	}
	else if (philo->total_eat > 0)
	{
		while (!philo->full && philo->dead == 0 && i < philo->total_eat)
		{
			eat(philo);
			printf("%lldms philo %d is sleeping\n", timestamp() - philo->time_init, philo->id);
    		usleep(philo->time_tosleep);
    		printf("%lldms philo %d is thinking\n", timestamp() - philo->time_init, philo->id);
			i++;
		}
	}*/
	return (NULL);
}

int	main(int ac, char **av)
{
	//int	i;
	int	error;
	t_param param;
	//int	num_philos_ate;

	//i = 0;
	//num_philos_ate = 0;
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
