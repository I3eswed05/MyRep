#include <stdlib.h>
//#include "libft.h"
#include <stdio.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, end - start);
	word[end - start] = '\0';
	return (word);
}

static void	free_all(char **result, int k)
{
	while (k > 0)
		free(result[--k]);
	free(result);
}

static int	fill_word(char **result, const char *s, char c, int *idx)
{
	int	start;
	int	i;

	i = *idx;
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	*idx = i;
	result[0] = word_dup(s, start, i);
	return (!result[0]);
}

static int	fill_split(char **result, const char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (fill_word(result + k, s, c, &i))
				return (k + 1);
			k++;
		}
		else
			i++;
	}
	result[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	words;
	int	err_k;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	err_k = fill_split(result, s, c);
	if (err_k)
	{
		free_all(result, err_k - 1);
		return (NULL);
	}
	return (result);
}
