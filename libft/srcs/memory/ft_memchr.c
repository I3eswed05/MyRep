/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:45:22 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/07 22:33:28 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		uc;
	size_t				i;

	src = s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (src[i] == uc)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
