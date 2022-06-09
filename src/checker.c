/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    checker(t_param *param)
{
    int i;

    while (1)
    {
        i = -1;
        while (i++ < param->num_philo)
        {
            if (param->num_eat > 0)
            {
                if (param->philo[i].meal_count == param->num_eat)
                    param->philo[i].full = 1;
            }
            pthread_mutex_lock(&param->meal_check);
            if (timestamp() - param->philo[i].l_meal > param->philo[i].time_todie)
            {
                printf("%lldms philo %d die\n", timestamp() - param->philo[i].time_init, param->philo[i].id);
                param->philo[i].dead = 1;
            }
            pthread_mutex_unlock(&param->meal_check);
            i++;
        }
    }
}