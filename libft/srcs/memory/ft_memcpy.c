/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:46 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/04 21:51:51 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (NULL);
	a = dest;
	b = src;
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}
