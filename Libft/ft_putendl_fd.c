#include "libft.h"

void	ft_putendl_fd.c(char *s, int fd)
{
	if (!s)
		return;
	ft_putstr_fd(s, fd);
	write (fd, '\n', 1);
}
