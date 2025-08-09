#include <stdlib.h>
#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *p;
    size_t  slen;
    size_t  actual_len;

    if (s == NULL)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup("")); // empty string
    if (len > s_len - start)
        actual_len = s_len - start;
    else
        actual_len = len;
    p = malloc(actual_len + 1);
    if (p == NULL)
        return (NULL);
    ft_memcpy(p, s + start, actual_len);
    p[actual_len] = '\0';
    return (p);
}

