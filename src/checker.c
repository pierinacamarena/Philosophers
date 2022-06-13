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

// int     check_full(t_param *param, t_philo *philo)
// {
//     // 	if (param->num_eat && param->ph[i].full == 2)
// // 	{
// // 		printf("%lldms philo %d full\n", actual_time() - param->ph[*k].ttinit,
// // 			param->ph[*k].id);
// // 		(*ret)++;
// // 		param->ph[*k].full = 1;
// // 	}
// }

void    *checker(void *temp)
{
    int i;
    int all_ate;
    t_param *param;
    t_philo *philos;

    param = (t_param *)temp;
    philos = param->philo;
    all_ate = 0; 
    while (1)
    {
        usleep(10);
        i = -1;
        while (i++ < param->num_philo)
        {
            if (philos[i].full == 2 && philos[i].total_eat > 0)
                {
					printf("%lldms philo %d is full\n", timestamp() - philos[i].time_init, philos[i].id);
					all_ate++;
                    philos[i].full = 1;
                }
            if (all_ate == param->num_eat)
            {
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				printf("%lldms all philos ate\n", timestamp() - philos[i].time_init);
				printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				return (NULL);
			}
            // pthread_mutex_lock(&param->meal_check);
            // if (timestamp() - philos[i].l_meal >philos[i].time_todie)
            // {
            //     printf("%lldms philo %d died\n", timestamp() - philos[i].time_init, philos[i].id);
            //     philos[i].dead = 1;
            // }
            // pthread_mutex_unlock(&param->meal_check);
            // if (philos[i].dead == 1)
            //     return (NULL);
		}
    }
}