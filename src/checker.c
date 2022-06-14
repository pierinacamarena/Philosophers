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

void    *checker(void *temp)
{
    int i;
    t_param *param;
    t_philo *philos;

    param = (t_param *)temp;
    philos = param->philo;
    while (1)
    {
        ft_usleep(20, NULL);
        i = -1;
        while (++i < param->num_philo)
        {
            if (param->num_eat > 0 && philos[i].full == 2)
	        {
		        printf("%lldms philo %d full\n", current_time() - philos[i].time_init,
			        philos[i].id);
		        param->all_ate++;
		        philos[i].full = 1;
	        }
            if (param->all_ate == param->num_eat)
                break ;
		}
    }
}
