/*
void	death_checker(t_rules *r, t_philosopher *p)
{
	int i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_death)
			{
				action_print(r, i, "died");
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}



void	*death_is_near(void *tmp)
{
	t_table		*all;
	t_philo		*p;
	int			i;

	all = tmp;
	p = all->philo;
	while (1)
	{
		i = -1;
		while (++i < all->count_philo)
		{
			if (all->count_of_lunch)
				if (p->count_eat == all->count_of_lunch)
					return (NULL);
			if (get_timestamp() - p[i].last_eat > p[i].time_to_die)
			{
				all->flag_of_death = 1;
				pthread_mutex_lock(&all->print);
				printf("%lld %d" YEL " is died"RESET"\n",
					get_timestamp() - p->time_start, p->id);
				return (NULL);
			}
		}
	}
	return (NULL);
}

*/