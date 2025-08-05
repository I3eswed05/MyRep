#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_memset_bzero(void)
{
    char str1[10] = "123456789";  // Original string
    char str2[10] = "123456789";  // Copy for comparison
    
    // 1. Test ft_memset
    ft_memset(str1, 'X', 5);
    memset(str2, 'X', 5);
    printf("ft_memset: %s\n", str1);  // Should print "XXXXX6789"
    printf("   memset: %s\n", str2);  // Should match exactly

    // 2. Reset the strings
    strcpy(str1, "123456789");
    strcpy(str2, "123456789");
    
    // 3. Test ft_bzero
    ft_bzero(str1, 3);
    bzero(str2, 3);
    
    printf("ft_bzero: ");
    for (int i = 0; i < 10; i++) printf("%d ", str1[i]);  // ASCII values
    printf("\n   bzero: ");
    for (int i = 0; i < 10; i++) printf("%d ", str2[i]);  // Should match
    printf("\n");
}

int main(void)
{
    test_memset_bzero();
    return 0;
}
