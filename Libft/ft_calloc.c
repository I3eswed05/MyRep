#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (size != 0 && nmemb > SIZE_MAX / size) //OverFlow checking
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
