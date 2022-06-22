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
	if (philo->id % 2)
		usleep(15000);
	while (philo->dead != 1 || philo->full != 1)
	{
		if (philo->full > 0 || eat(philo) == 1)
			break;
		if (philo->meal_count == philo->total_eat)
			philo->full = 2;
		if (philo->dead || philo->full > 0 || philo_sleep(philo) == 1)
			break;
		if (philo->dead != 1)
    		locked_print(philo, 4);
	}
	return (NULL);
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
