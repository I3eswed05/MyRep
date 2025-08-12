#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t 	 len;
    char   	*new_str;
    unsigned int i;

    if (!s || !f)
        return NULL;

    len = ft_strlen(s);
    new_str = malloc(len + 1);
    if (!new_str)
        return NULL;

    for (i = 0; i < len; i++)
        new_str[i] = f(i, s[i]);

    new_str[i] = '\0';
    return new_str;
}
