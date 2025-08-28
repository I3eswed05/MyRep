/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:13:43 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/09 14:17:27 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*second;
	size_t				i;

	i = 0;
	first = s1;
	second = s2;
	while (i < n && first[i] == second[i])
		i++;
	if (i < n)
		return (first[i] - second[i]);
	return (0);
}
