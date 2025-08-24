/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:33:19 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/09 19:48:50 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
