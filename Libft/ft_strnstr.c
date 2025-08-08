#include "libft.h"
#include <stdio.h>

char	*strnstr(const char *haystack, const char *needle, size_t n)
{
	if (needle[0] == '\0')
		return ((char *)(haystack));
	size_t		i;
	size_t		j;
	const char	*p;

	p = NULL;
	i = 0;
	j = 0;
	while (i < n)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((i + j) < n && haystack[i + j] == needle[j] && needle[j] !='\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}

int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle1 = "world";
    const char *needle2 = "wor";
    const char *needle3 = "WORLD";
    const char *needle4 = "";
    const char *needle5 = "o, w";

    // Test 1: needle found within n
    printf("Test 1: %s\n", strnstr(haystack, needle1, 13)); // expect "world!"

    // Test 2: needle found within shorter n
    printf("Test 2: %s\n", strnstr(haystack, needle2, 10)); // expect "world!"

    // Test 3: needle not found (case-sensitive)
    printf("Test 3: %s\n", strnstr(haystack, needle3, 13)); // expect (null)

    // Test 4: empty needle returns haystack
    printf("Test 4: %s\n", strnstr(haystack, needle4, 13)); // expect "Hello, world!"

    // Test 5: needle crosses boundary of n
    printf("Test 5: %s\n", strnstr(haystack, needle5, 5));  // expect (null)

    return 0;
}

