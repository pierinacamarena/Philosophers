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
	while (philo->dead != 1 && philo->full != 1)
	{
		if (philo->full > 0 || eat(philo) == 1)
			break;
		if (philo->meal_count == philo->total_eat)
			philo->full = 2;
		if (philo->dead || philo->full > 0 || philo_sleep(philo) == 1)
			break;
		// printf("%lldms philo %d is sleeping\n", current_time() - philo->time_init, philo->id);
  	  	// usleep(philo->time_tosleep);
		//if (philo->full == 0 && philo->dead == 0)
    	printf("%lldms philo %d is thinking\n", current_time() - philo->time_init, philo->id);
		//i++;
	}
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
