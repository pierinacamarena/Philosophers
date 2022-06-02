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

void    philos_setup(t_param *param)
{
    int i;

    i = 0;
    param->philo = malloc(sizeof(t_philo) * param->num_philo);
	if (!param->philo)
		return;
    while (i < param->num_philo)
    {
        param->philo[i].id = i + 1; 
        param->philo[i].time_init = timestamp();
        param->philo[i].time_toeat = param->t_eat;
        param->philo[i].time_tosleep = param->t_sleep;
        param->philo[i].time_todie = param->t_die;
        param->philo[i].status = 0;
        param->philo[i].full = 0;
        param->philo[i].meal_count = 0;
        param->philo[i].dead = 0;
        param->philo[i].left_f = &param->forks[i];
        if (i < param->num_philo - 1)
            param->philo[i].right_f = &param->forks[i + 1];
        else
            param->philo[i].right_f = &param->forks[0];
        i++;
    }
}