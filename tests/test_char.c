#include "ft_printf.h"    
#include "printf_tests.h"

/*
** c: If no l is present: unsigned char, with character written. If l is present: wint_t (wide character). 
**
** To do: Account for l option.
*/

void    test_char(void)
{
    ft_printf("\n=====CHAR TESTS====\n");
    ft_printf("(ft_3a) My ft_printf doing a c conversion of int = 65: |%c|\n", 65);
	ft_printf("(ft_3b) My ft_printf doing an lc conversion of int = 65 (ignores the l flag): |%lc|\n", 65);
    ft_printf("(ft_3c) ft_printf with c conversion with a space (ignores the space flag): |% c|\n", 65);
	ft_printf("(ft_3d) ft_printf with c conversion of int = 65 with field-width 10: |%10c|\n", 65);
	ft_printf("(ft_3e) ft_printf with c conversion of int = 65 with field-width -10: |%-10c|\n", 65);
	ft_printf("(ft_3f) ft_printf with c conversion of int = 65 with precision 10 (ignores precision): |%.10c|\n", 65);
    printf("(3a) Printf with c conversion of int = 65: |%c|\n", 65);
    printf("(3b) Printf with lc conversion of int = 65 (ignores the l flag): |%lc|\n", 65);
    printf("(3c) Printf with c conversion with a space (ignores the space flag): |% c|\n", 65);
	printf("(3d) Printf with c conversion of int = 65 with field-width 10: |%10c|\n", 65);
	printf("(3e) Printf with c conversion of int = 65 with field-width -10: |%-10c|\n", 65);
	printf("(3f) Printf with c conversion of int = 65 with precision 10 (ignores precision): |%.10c|\n", 65);
}