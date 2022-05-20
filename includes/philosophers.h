/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:57 by pcamaren          #+#    #+#             */
/*   Updated: 2021/09/09 18:15:00 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct  s_fork
{
    pthread_mutex_t	fork;
    int             id;
}               t_fork;

typedef struct  s_philo
{
    int         id;
    long long   time_init;
    long long   l_meal;
    int         time_teat;
    int         time_tosleep;
    int         time_todie;
    int         status;
    int         full;
    int         meal_count;
    t_fork      *left_f;
    t_fork      *right_f;
}               t_philo;

typedef struct     s_param
{
    int     num_philo;
    int     t_die;
    int     t_eat;
    int     t_sleep;
    int     num_eat;
    t_fork  *forks;
    t_philo *p;
}               t_param;

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int     arg_parsing(int ac, char **av, t_param *param);
void	error_arg(void);
void 	error_parsing(void);

#endif
