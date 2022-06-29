/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static  void    check_philo_fork(t_fork *fork, t_philo *philo)
{
    while (check_fork_id(fork, philo))
    {
        ft_usleep(2, NULL);
    }
    pthread_mutex_lock(&fork->_id_pf);
    pthread_mutex_lock(&fork->fork);
    fork->id_pf = philo->id;
    pthread_mutex_unlock(&fork->_id_pf);
}

int    eat(t_philo *philo)
{
    t_param *param;

    param = philo->params;
    if (philo->id % 2 == 0)
        check_philo_fork(philo->left_f, philo);
    else 
        check_philo_fork(philo->right_f, philo);
    if (philo->id % 2 == 0)
        check_philo_fork(philo->right_f, philo);
    else if (philo->id % 2 != 0 && philo->total_philo > 1)
        check_philo_fork(philo->left_f, philo);
    if (!check_death(param) && philo->total_philo > 1)
    {
        locked_print(philo, 1);
        locked_print(philo, 1);
        locked_print(philo, 2);
        pthread_mutex_lock(&(philo->_meal_count));
        philo->meal_count++;
        pthread_mutex_unlock(&(philo->_meal_count));
        pthread_mutex_lock(&(philo->_l_meal));
        philo->l_meal = current_time();
        pthread_mutex_unlock(&(philo->_l_meal));
        my_sleep(philo, philo->time_toeat);
    }
    if (philo->total_philo > 1)
        pthread_mutex_unlock(&(philo->left_f->fork));
    pthread_mutex_unlock(&(philo->right_f->fork));
    return (0);
}

int    philo_sleep(t_philo *philo)
{
    t_param *param;

    param = philo->params;
    if (!check_death(param))
    {
        locked_print(philo, 3);
        my_sleep(philo, philo->time_tosleep);
    }
    return (0);
}