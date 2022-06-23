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

static void    greedy_philo_check(int *id_dirty, int id, pthread_mutex_t *fork)
{
    if (*id_dirty == id)
        usleep(10);
    pthread_mutex_lock(fork);
    *id_dirty = id;
}

int    eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork));
	    if (philo->dead != 1)
            locked_print(philo, 1);
    }
    else
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
	    if (philo->dead != 1)
            locked_print(philo, 1);
    }
    if (philo->id % 2 == 0)
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
	    if (philo->dead != 1)
            locked_print(philo, 1);
    }
    else if (philo->id % 2 != 0 && philo->total_philo > 1)
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork));

	    if (philo->dead != 1)
            locked_print(philo, 1);
    }
    if (philo->dead != 1 && philo->total_philo > 1)
    {
        locked_print(philo, 2);
        pthread_mutex_lock(&(philo->params->meal_count));
        philo->meal_count++;
        pthread_mutex_unlock(&(philo->params->meal_count));
        my_sleep(philo, philo->time_toeat);
        pthread_mutex_lock(&(philo->params->meal_update));
        philo->l_meal = current_time();
        pthread_mutex_unlock(&(philo->params->meal_update));
    }
    pthread_mutex_unlock(&(philo->left_f->fork));
    pthread_mutex_unlock(&(philo->right_f->fork));
    return (0);
}

int    philo_sleep(t_philo *philo)
{
    if (philo->dead == 0)
    {
        locked_print(philo, 3);
        my_sleep(philo, philo->time_tosleep);
    }
    return (0);
}