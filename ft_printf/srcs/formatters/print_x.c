/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:14:07 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:14:10 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_x(va_list args)
{
	unsigned int	value;
	char			*str;
	int				len;

	value = va_arg(args, unsigned int);
	str = ft_itoa_base((unsigned long)value, 16, 0);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
