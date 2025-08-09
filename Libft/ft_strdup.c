char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
