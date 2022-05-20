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

t_fork  *create_fork(t_param param)
{
    t_fork *forks;
    int     i;

    i = 0;
    forks = malloc(sizeof(t_fork) * param.num_philo);
    if (!forks)
        return (NULL);
    while (i < param.num_philo)
    {
        pthread_mutex_init(&forks[i].fork, NULL);
        forks[i].id = i;
    }
    return (forks);       
}

int arg_parsing(int ac, char **av, t_param *param)
{
    param->num_philo = ft_atoi(av[1]);
    if (param->num_philo < 2)
        return (1);
    param->t_die = ft_atoi(av[2]);
    if (param->t_die < 1)
        return (1);
    param->t_eat = ft_atoi(av[3]);
    if (param->t_eat < 1)
        return (1);
    param->t_sleep = ft_atoi(av[4]);
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
    return (0);
}
