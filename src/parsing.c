/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int  mutexes_init(t_param *param)
{
    if (pthread_mutex_init(&(param->printer), NULL))
		return (1);
	if (pthread_mutex_init(&(param->meal_check), NULL))
		return (1);
    return (0);
}
static  t_fork  *create_fork(int n)
{
    t_fork *tmp;
    int     i;

    i = 0;
    tmp = malloc(sizeof(t_fork) * n);
    if (!tmp)
        return (NULL);
    while (i < n)
    {
        pthread_mutex_init(&tmp[i].fork, NULL);
        tmp[i].id_dirty = i;
        i++;
    }
    return (tmp);       
}

int arg_parsing(int ac, char **av, t_param *param)
{
    param->num_philo = ft_atoi(av[1]);
    if (param->num_philo < 1)
        return (1);
    param->t_die = ft_atoi(av[2]);
    if (param->t_die < 1)
        return (1);
    param->t_eat = ft_atoi(av[3]);
    if (param->t_eat < 1)
        return (1);
    param->t_sleep = ft_atoi(av[4]);
    param->all_ate = 0;
    param->forks = create_fork(param->num_philo);
    if (!param->forks)
        return (0);
    if (param->t_sleep < 1)
        return (1);
    if (ac == 6)
    {
        param->num_eat = ft_atoi(av[5]);
        if (param->num_eat == 0)
            return (1);
    }
    else
        param->num_eat = 0;
    if (mutexes_init(param))
        return (1);
    return (0);
}
