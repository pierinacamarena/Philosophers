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

void    check_dead_full(t_param *param)
{
    int i;
    t_philo *philos;

    philos = param->philo;
    while (1)
    {
        ft_usleep(20, NULL);
        i = -1;
        while (++i < param->num_philo)
        {
            if (param->num_eat && (philos[i].full == 2))
	        {
		        param->all_ate++;
		        philos[i].full = 1;
	        }
            if (param->all_ate == param->num_philo)
            {
                printf("%lld all philo are full\n", current_time() - param->philo->time_init);
                return;
            }
		}
    }
}