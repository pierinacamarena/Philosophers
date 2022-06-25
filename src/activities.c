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

static void    greedy_philo_check(int *id_dirty, int id, pthread_mutex_t *fork, t_param *param)
{
    pthread_mutex_lock(&(param->meal_update));
    if (*id_dirty == id)
        usleep(10);
    pthread_mutex_unlock(&(param->meal_update));
    pthread_mutex_lock(fork);
    pthread_mutex_lock(&(param->meal_check));
    *id_dirty = id;
    pthread_mutex_unlock(&(param->meal_check));
}

int    eat(t_philo *philo)
{
    t_param *param;

    param = philo->params;

    if (philo->total_philo % 2 == 0 || philo->total_philo == 1)
    {
        if (philo->id % 2 == 0)
            greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork), param);
        else 
            greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork), param);
        if (philo->id % 2 == 0)
            greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork), param);
        else if (philo->id % 2 != 0 && philo->total_philo > 1)
            greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork), param);
    }
    else
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork), param);
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork), param);
    }
    if (!check_death(param) && philo->total_philo > 1)
    {
        locked_print(philo, 1);
        locked_print(philo, 1);
        locked_print(philo, 2);
        pthread_mutex_lock(&(param->meal_count));
        philo->meal_count++;
        pthread_mutex_unlock(&(param->meal_count));
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