#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*

int main(void)
{
    printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));  // Should return 1 (true)
    printf("ft_isalnum('9') = %d\n", ft_isalnum('9'));  // Should return 1 (true)
    printf("ft_isalnum('!') = %d\n", ft_isalnum('!'));  // Should return 0 (false)
    return (0);
}*/
