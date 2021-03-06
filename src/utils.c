/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:02:53 by pcamaren          #+#    #+#             */
/*   Updated: 2022/06/26 01:24:27 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	is_not_valid(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (is_not_valid(str))
		return (0);
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + ((*str++) - '0');
	return (nb * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

void	locked_print(t_philo *philo, int action)
{
	t_param	*param;

	param = philo->params;
	pthread_mutex_lock(&(param->meal_check));
	pthread_mutex_lock(&(param->printer));
	if (!check_death(param) && !check_full(philo))
	{
		if (action == 1)
			printf("%lld %d has taken a fork\n", \
			current_time() - philo->time_init, philo->id);
		else if (action == 2)
			printf("%lld %d is eating\n", \
			current_time() - philo->time_init, philo->id);
		else if (action == 3)
			printf("%lld %d is sleeping\n", \
			current_time() - philo->time_init, philo->id);
		else if (action == 4)
			printf("%lld %d is thinking\n", \
			current_time() - philo->time_init, philo->id);
	}
	pthread_mutex_unlock(&(param->printer));
	pthread_mutex_unlock(&(param->meal_check));
}
