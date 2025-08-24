/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:08:07 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/07 16:08:28 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	lefspc;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	lefspc = size - dstlen - 1;
	i = 0;
	while (src[i] != '\0' && i < lefspc)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int main(void)
{
    char dest[20] = "Hello";
    const char *src = "";
    size_t size = 20;

    size_t result = ft_strlcat(dest, src, size);
    printf("Result: %zu\n", result);
    printf("Dest after strlcat: %s\n", dest);

    return 0;
}
*/
