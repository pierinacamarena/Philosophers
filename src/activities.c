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

void    eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork));
	    printf("%lldms philo %d has taken a left fork\n", timestamp() - philo->time_init, philo->id);
    }
    else
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
        printf("%lldms philo %d has taken a right fork\n", timestamp() - philo->time_init, philo->id);
    }
    if (philo->id % 2 == 0)
    {
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork));
        printf("%lldms philo %d has taken a right fork\n", timestamp() - philo->time_init, philo->id);
    }
    else
    {
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork));
	    printf("%lldms philo %d has taken a left fork\n", timestamp() - philo->time_init, philo->id);
    }
    printf("%lldms philo %d is eating\n", timestamp() - philo->time_init, philo->id);
    philo->l_meal = timestamp();
    philo->meal_count++;
    if (philo->meal_count == philo->total_eat)
        philo->full = 1;
    printf("%lldms meal count of philo %d is %d\n", timestamp() - philo->time_init, philo->id, philo->meal_count);
    usleep(philo->time_toeat);
    pthread_mutex_unlock(&(philo->left_f->fork));
    printf("%lldms philo %d has dropped a left fork\n", timestamp() - philo->time_init, philo->id);
    pthread_mutex_unlock(&(philo->right_f->fork));
    printf("%lldms philo %d has dropped a right fork\n", timestamp() - philo->time_init, philo->id);
}
