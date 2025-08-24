/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:12:26 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:12:29 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_dispatch_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(args));
	else if (specifier == 's')
		return (ft_print_str(args));
	else if (specifier == 'p')
		return (ft_print_ptr(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_d(args));
	else if (specifier == 'u')
		return (ft_print_u(args));
	else if (specifier == 'x')
		return (ft_print_x(args));
	else if (specifier == 'X')
		return (ft_print_upper_x(args));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}
