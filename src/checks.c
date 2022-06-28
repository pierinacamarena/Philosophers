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
    int time_die_var;

    pthread_mutex_lock(&param->time_die);
    time_die_var = param->t_die;
    pthread_mutex_unlock(&param->time_die);
    pthread_mutex_lock(&param->philo[i]._l_meal);
    if (current_time() - param->philo[i].l_meal > time_die_var)
    {
        pthread_mutex_unlock(&param->philo[i]._l_meal);
        return (1);
    }
    pthread_mutex_unlock(&param->philo[i]._l_meal);
    return (0);
}

int check_death(t_param *param)
{
    pthread_mutex_lock(&param->_died);
    if (param->died == 1)
    {
        pthread_mutex_unlock(&param->_died);
        return (1);
    }
    pthread_mutex_unlock(&param->_died);
    return (0);
}

int check_full(t_philo *philo)
{
    pthread_mutex_lock(&philo->_full);
    if (philo->full == 1)
    {
        pthread_mutex_unlock(&philo->_full);
        return (1);
    }
    pthread_mutex_unlock(&philo->_full);
    return (0);
}

int check_full_two(t_param *param, int i)
{
    pthread_mutex_lock(&param->philo[i]._full);
    if (param->philo[i].full == 2)
    {
        pthread_mutex_unlock(&param->philo[i]._full);
        return (1);
    }
    pthread_mutex_unlock(&param->philo[i]._full);
    return (0);
}

int check_num_eat(t_param *param)
{
    pthread_mutex_lock(&param->_num_eat);
    if (param->num_eat > 0)
    {
        pthread_mutex_unlock(&param->_num_eat);
        return (1);
    }
    pthread_mutex_unlock(&param->_num_eat);
    return (0);
}

int check_fork_id(t_fork *fork, t_philo *philo)
{
    int id_philo;

    pthread_mutex_lock(&philo->_id);
    id_philo = philo->id;
    pthread_mutex_unlock(&philo->_id);
    pthread_mutex_lock(&fork->_id_pf);
    if (fork->id_pf == id_philo)
    {
        pthread_mutex_unlock(&fork->_id_pf);
        return (1);
    }
    pthread_mutex_unlock(&fork->_id_pf);
    return (0);
}