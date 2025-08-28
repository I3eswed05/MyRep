/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:11:41 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/09 17:14:40 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;
	size_t	actual_len;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		actual_len = slen - start;
	else
		actual_len = len;
	p = malloc(actual_len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s + start, actual_len);
	p[actual_len] = '\0';
	return (p);
}
