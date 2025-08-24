/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:13:34 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:13:36 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(va_list args)
{
	void	*ptr;
	char	*str;
	int		len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	str = ft_itoa_base((unsigned long)ptr, 16, 0);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
	return (len + 2);
}
