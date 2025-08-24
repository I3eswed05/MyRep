/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:40:43 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/06 23:09:34 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		s = src + n;
		d = dest + n;
		while (n--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	else
		return (dest);
	return (dest);
}
