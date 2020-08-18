#include "ft_printf.h"    
#include "printf_tests.h"

/*
** void * printed in hexadecimal (as if by %#x or %#lx)
**
** To-do: account for l option.
*/

void    test_pointer(void)
{
    void        *p_test;
    int             i;

    i = 42;
    p_test = &i;
    ft_printf("\n====POINTER TESTS====\n");
    ft_printf("(ft_5a) Ft_printf with p conversion: |%p|\n", p_test);
    ft_printf("(ft_5b) Ft_printf with p conversion, width = 20: |%20p|\n", p_test);
    ft_printf("(ft_5c) Ft_printf with p conversion, width = -20: |%-20p|\n", p_test);
    ft_printf("(ft_5d) Ft_printf with p conversion, zero-padded = 20: |%020p|\n", p_test);
    printf("(5a) Printf with p conversion: |%p|\n", p_test);
    printf("(5b) Printf with p conversion, width = 20: |%20p|\n", p_test);
    printf("(5c) Printf with p conversion, width = 20: |%-20p|\n", p_test);
    printf("(5d) Printf with p conversion, zero-padded = 20: |%020p|\n", p_test);
}