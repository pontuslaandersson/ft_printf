#include "ft_printf.h"
#include "printf_tests.h"

void    test_leaks(void)
{
	int     ret;
    void        *p_test;
    int             i;

    i = 42;
    p_test = &i;
    ret = -1;
    ft_printf("\n");
    ft_printf("====LEAKS====\n");
    //ret = ft_printf("Test.\n");
    //ft_printf("Return of last ft_printf command (should be 6): %-10d.\n", ret); //No leaks!
	//ret = ft_printf("s test: %s.\n", "test");
    //ft_printf("Return of last ft_printf command (should be 14): %d\n", ret); //No leaks!
    //ret = ft_printf("%s.\n", "test");
    //ft_printf("Return of last ft_printf command (should be 6): %d\n", ret); //No leaks!
    //ret = ft_printf("Test: %d\n", 32);
    //ft_printf("Return of last ft_printf command (should be 9): %d\n", ret); //No leaks!
    //ret = ft_printf("f: %.3f\n", 6841.913);
    //ft_printf("Return of last ft_printf command (should be 12): %d\n", ret); //No leaks!
    //ret = ft_printf("f: %12.3f\n", 6841.913);
    //ft_printf("Return of last ft_printf command (should be 16): %d\n", ret); //No leaks!
    //ret = ft_printf("s test: %-10s.\n", "test");
    //ft_printf("Return of last ft_printf command (should be 20): %d\n", ret); //No leaks!
    //ret = ft_printf("p test: %p.\n", p_test);
    //ft_printf("Return of last ft_printf command (should be 24): %d\n", ret); //No leaks!
    //test_returns();
}