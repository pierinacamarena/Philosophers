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

int check_all_ate(t_philo *philo)
{
    int total_eat;

    pthread_mutex_lock(&philo->_total_eat);
    total_eat = philo->total_eat;
    pthread_mutex_unlock(&philo->_total_eat);
    pthread_mutex_lock(&philo->_meal_count);
    if (philo->meal_count == total_eat)
    {
        pthread_mutex_unlock(&philo->_meal_count);
        return (1);
    }
    pthread_mutex_unlock(&philo->_meal_count);
    return (0);
}