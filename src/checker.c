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

static int  check_helper(t_param *param, int *i)
{
    int ret;

    ret = 0;
    if ((check_num_eat(param)) && check_full_two(param, *i))
    {
        pthread_mutex_lock(&(param->_all_ate));
	    param->all_ate++;
        pthread_mutex_unlock(&(param->_all_ate));
        pthread_mutex_lock(&(param->philo[*i]._full));
	    param->philo[*i].full = 1;
        pthread_mutex_unlock(&(param->philo[*i]._full));
    }
    if (check_last_meal(param, *i))
    {
        pthread_mutex_lock(&(param->_died));
        param->died = 1;
        pthread_mutex_unlock(&(param->_died));
	    pthread_mutex_lock(&(param->printer));
        printf("%lld %d died\n", current_time() - param->philo[*i].time_init,
		param->philo[*i].id);
	    pthread_mutex_unlock(&(param->printer));
        ret = 1;
    }
    return (ret);
}

void    check_dead_full(t_param *param)
{
    int i;
    while (1)
    {
        ft_usleep(20, NULL);
        i = -1;
        while (++i < param->num_philo)
        {
            if (check_helper(param, &i))
                return;
            if (param->all_ate == param->num_philo)
            {
                printf("%lld all philo are full\n", current_time() - param->philo->time_init);
                return;
            }
		}
    }
}