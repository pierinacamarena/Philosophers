static int		full_or_deat(t_var *var, int *k, int *ret)
{
	if (var->notepmt && var->ph[*k].full == 2)
	{
		printf("%lldms %d full\n", actual_time() - var->ph[*k].ttinit,
			var->ph[*k].id);
		(*ret)++;
		var->ph[*k].full = 1;
	}
	if (actual_time() > var->ph[*k].lmeal + var->ph[*k].ttdie)
		var->ph[*k].status = 1;
	if (var->ph[*k].full != 1 && var->ph[*k].status == 1)
	{
		printf("%lldms %d dead\n", actual_time() - var->ph[*k].ttinit,
			var->ph[*k].id);
		*k = -1;
		while (++(*k) < var->number_of_philosopher)
			var->ph[*k].status = 1;
		return (1);
	}
	return (0);
}