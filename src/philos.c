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
    while (i < param->num_philo)
    {
        param->p[i].id = i + 1;
        param->p[i].time_init = actual_time();
        param->p[i].time_teat = param->t_eat;
        param->p[i].time_tosleep = param->t_sleep;
        param->p[i].time_todie = param->t_die;
        param->p[i].status = 0;
        param->p[i].full = 0;
        param->p[i].meal_count = 0;
        param->p[i].left_f = &param->forks[i];
        if (i < param->num_philo - 1)
            param->p[i].right_f = &param->forks[i + 1];
        else
            param->p[i].right_f = &param->forks[0];
        i++;
    }
}