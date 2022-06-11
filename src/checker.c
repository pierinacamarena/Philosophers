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
    int all_ate;

    all_ate = 0; 
    while (1)
    {
        usleep(10);
        i = -1;
        while (i++ < param->num_philo)
        {
            //if (dead_full_checker())
            //    return ;
            //if 
            if (param->num_eat > 0)
            {
                if (param->philo[i].meal_count == param->num_eat)
                {
                    printf("++++++++++++++++++-------------------------+++++++++++++++++++\n");
                    printf("for philo %d the mealcount is %d\n", param->philo[i].id, param->philo[i].meal_count);

                    printf("inside checker, entering to modify the value of philo->full\n");
                    printf("modifying philo %d\n", param->philo[i].id);
                    param->philo[i].full = 1;
                    printf("inside checker new value of full is %d\n", param->philo[i].full);
                    all_ate++;
                    printf("value of all ate is %d\n", all_ate);
                    printf("++++++++++++++++++-------------------------+++++++++++++++++++\n");
                }
            }
            if (all_ate == param->num_eat)
            {
                printf("all philos ate\n");
                return ;
            }
            /*pthread_mutex_lock(&param->meal_check);
            if (timestamp() - param->philo[i].l_meal > param->philo[i].time_todie)
            {
                printf("%lldms philo %d died\n", timestamp() - param->philo[i].time_init, param->philo[i].id);
                param->philo[i].dead = 1;
            }
            pthread_mutex_unlock(&param->meal_check);
            if (param->philo[i].dead == 1)
                break;*/
            i++;
        }
    }
}