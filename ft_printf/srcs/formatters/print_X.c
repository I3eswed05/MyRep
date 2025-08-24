/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:14:15 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:14:19 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_upper_x(va_list args)
{
	unsigned int	value;
	char			*str;
	int				len;

	value = va_arg(args, unsigned int);
	str = ft_itoa_base((unsigned long)value, 16, 1);
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	free(str);
	return (len);
}
