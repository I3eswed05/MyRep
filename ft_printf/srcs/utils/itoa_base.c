/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:12:54 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:12:57 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	count_base_len(unsigned long value, int base)
{
	int	len;

	len = 1;
	while (value >= (unsigned long)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long value, int base, int uppercase)
{
	char	*digits;
	char	*str;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase == 0)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	len = count_base_len(value, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = digits[value % base];
		value /= base;
	}
	return (str);
}
