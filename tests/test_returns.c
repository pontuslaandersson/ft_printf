#include "ft_printf.h"    
#include "printf_tests.h"

/*
** returns: Whether ft_printf produces the correct return value.
**
** Right now, it doesn't.
*/

void    test_returns(void)
{
    int     ret;
    void        *p_test;
    int             i;

    i = 42;
    p_test = &i;
    ret = -1;
    ft_printf("\n"); // Works!
    ft_printf("====RETURNS====\n"); // Works!
    ret = ft_printf("Test.\n"); // Works!
    ft_printf("Return of last ft_printf command (should be 6): %d\n", ret); // Works!
    ft_printf("\n"); // Works!
    ret = ft_printf("s test: %s.\n", "test"); // Works!
    ft_printf("Return of last ft_printf command (should be 14): %d\n", ret); // Works!
    ft_printf("\n"); // Works!
    ret = ft_printf("%s.\n", "test"); // Works!
    ft_printf("Return of last ft_printf command (should be 6): %d\n", ret); // Works!
    ft_printf("\n"); // Works!
    ret = ft_printf("Test: %d\n", 32);
    ft_printf("Return of last ft_printf command (should be 9): %d\n", ret);
    ft_printf("\n");
    ret = ft_printf("f: %.3f\n", 6841.913);
    ft_printf("Return of last ft_printf command (should be 12): %d\n", ret);
    ft_printf("\n");
    ret = ft_printf("f: %12.3f\n", 6841.913);
    ft_printf("Return of last ft_printf command (should be 16): %d\n", ret);
    ft_printf("\n");
    ret = ft_printf("s test: %10s.\n", "test");
    ft_printf("Return of last ft_printf command (should be 20): %d\n", ret);
    ft_printf("\n");
    ret = ft_printf("p test: %p.\n", p_test);
    ft_printf("Return of last ft_printf command (should be 24): %d\n", ret);
    ft_printf("\n");
	ret = ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir");
	ft_printf("Return of last ft_printf command (should be 150): %d\n", ret);
    ft_printf("\n");
    /*ft_printf("====THE REAL PRINTF====\n");
    ret = printf("Test.\n");
    printf("Return of last printf command (should be 6): %d\n", ret);
    ft_printf("\n");
    ret = printf("s test: %s.\n", "test");
    printf("Return of last printf command (should be 14): %d\n", ret);
    ft_printf("\n");
    ret = printf("%s.\n", "test");
    printf("Return of last printf command (should be 6): %d\n", ret);
    ft_printf("\n");
    ret = printf("Test: %d\n", 32);
    printf("Return of last printf command (should be 9): %d\n", ret);
    ft_printf("\n");
    ret = printf("f: %.3f\n", -6841.9);
    printf("Return of last printf command (should be 13): %d\n", ret);
    ft_printf("\n");
    ret = printf("s test: %10s.\n", "test");
    printf("Return of last printf command (should be 20): %d\n", ret);
    ft_printf("\n");
    ret = printf("p test: %p.\n", p_test);
    printf("Return of last printf command (should be 24): %d\n", ret);*/
}