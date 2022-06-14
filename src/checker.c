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

int     check_full(t_param *param, t_philo *philos, int *i, int *all_ate)
{
    if (param->num_eat && philos[*i].full == 2)
	{
		printf("%lldms philo %d full\n", timestamp() - philos[*i].time_init,
			philos[*i].id);
		(*all_ate)++;
		philos[*i].full = 1;
	}
    return (0);
}

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
            if (check_full(param, philos, &i, &all_ate))
                return (NULL);
            if (all_ate == param->num_eat)
                return (NULL);
		}
    }
}