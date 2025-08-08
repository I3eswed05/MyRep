#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*S1;
	const unsigned char	*S2;
	size_t			i;

	i = 0;
	S1 = s1;
	S2 = s2;
	while (i < n && S1[i] == S2[i])
		i++;
	if (i < n)
		return ((unsigned char)(S1[i]) - (unsigned char)(S2[i]));
	return (0);
}
