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

void    checker(t_param *param, t_philo *ph)
{
    int i;

    while (1)
    {
        i = -1;
        while (i++ < param->num_philo)
        {
            if (param->num_eat > 0)
            {
                if (ph->meal_count == param->num_eat)
                    ph->full = 1;
            }
            
        }
    }
}