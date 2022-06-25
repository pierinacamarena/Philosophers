/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:40 by pcamaren          #+#    #+#             */
/*   Updated: 2022/06/25 16:54:42 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_last_meal(t_param *param, int i)
{
    pthread_mutex_lock(&param->meal_check);
    if (current_time() - param->philo[i].l_meal > param->t_die)
    {
        pthread_mutex_unlock(&param->meal_check);
        return (1);
    }
    pthread_mutex_unlock(&param->meal_check);
    return (0);
}
