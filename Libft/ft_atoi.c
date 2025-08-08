int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		if (result > (unsigned int)INT_MAX && sign == 1)
			return (-1);
		else if (result > (unsigned int)INT_MIN && sign == -1)
			return (0);
		str++;
	}
	return ((int)(result * sign));
}
