/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:43:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/07 14:34:07 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	cpylen;

	srclen = ft_strlen(src);
	if (size > 0)
	{
		if (srclen >= size)
			cpylen = size - 1;
		else
			cpylen = srclen;
		ft_memcpy(dst, src, cpylen);
		dst[cpylen] = '\0';
	}
	return (srclen);
}
