/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:25:15 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/12 14:25:51 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			buffer[12];
	int				i;
	int				neg;

	i = 11;
	buffer[i] = '\0';
	neg = 0;
	if (n < 0)
	{
		num = (unsigned int)(-(long)n);
		neg = 1;
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = '0' + (num % 10);
		num /= 10;
	}
	if (neg)
		buffer[--i] = '-';
	write(fd, &buffer[i], 11 - i);
}
