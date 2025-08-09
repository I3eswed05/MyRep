#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	j;
	size_t	found;
	size_t	len;

	start = 0;
	end = ft_strlen(s1) - 1;
	j = 0;
	while (s1[start] != '\0')
	{
		found = 0;
		j = 0;
		while(set[j] != '\0')
		{
			if (s1[start] == set[j])
			{
				start++;
				found = 1;
				break;
			}
				j++;
		}
		if (found == 0)
			break;
	}
	while (end > start)
	{
		found = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[end] == set[j])
			{
				end--;
				found = 1;
				break;
			}
			j++;
		}
		if (found == 0)
			break;
	}
	len = end - start + 1;
	return (ft_substr(s1, start, len));

}
