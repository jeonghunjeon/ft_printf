	int	nbr;
	int	i;
	int	j;

	i = 0;
	nbr = va_arg(ap, unsigned int);
	while (base[i] != '\0')
	{
		j = 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[i + j] != '\0')
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (ft_putnbrbase(nbr, base));