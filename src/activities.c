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
	    printf("%lldms philo %d has taken a left fork\n", current_time() - philo->time_init, philo->id);
    }
    else
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
        printf("%lldms philo %d has taken a right fork\n", current_time() - philo->time_init, philo->id);
    }
    if (philo->id % 2 == 0)
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
        printf("%lldms philo %d has taken a right fork\n", current_time() - philo->time_init, philo->id);
    }
    else
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork));
	    printf("%lldms philo %d has taken a left fork\n", current_time() - philo->time_init, philo->id);
    }
    printf("%lldms philo %d is eating\n", current_time() - philo->time_init, philo->id);
    philo->l_meal = current_time();
    philo->meal_count++;
    my_sleep(philo, philo->time_toeat);
    pthread_mutex_unlock(&(philo->left_f->fork));
    pthread_mutex_unlock(&(philo->right_f->fork));
    return (0);
}

int    philo_sleep(t_philo *philo)
{
    if (philo->dead == 0)
    {
        printf("%lldms philo %d is sleeping\n", current_time() - philo->time_init, philo->id);
        my_sleep(philo, philo->time_tosleep);
    }
    return (0);
}