#include "ft_printf.h"    
#include "printf_tests.h"

/*
** s: If no l is present: const char * arg expected to be a pointer to a string, with string written excluding the null byte;
** if precision given, the number of characters is limited by such, and no null byte is needed.
** If l is present: wchar_t * (array of wide characters). 0 flag is not used for s conversions.
**
** To-do: account for l option.
*/

void    test_strings(void)
{
    //wchar_t     *s = "Widechar string.";

    ft_printf("\n====STRING TESTS====\n");
    //printf("(1) This is how printf prints an unformatted string.\n");
    ft_printf("(ft_1) My ft_printf with an unformatted string.\n");
    ft_printf("(ft_2a) My ft_printf with a string as an argument: |%s|\n", "string1");
    ft_printf("(ft_2b) My ft_printf with a string as an argument |%s| when it's in the middle of a larger format string.\n", "__string2__");
	ft_printf("(ft_2c) My ft_printf with a string as an argument with a width of 10: |%10s|\n", "string3");
    ft_printf("(ft_2d) My ft_printf with a string as an argument with a negative (left-aligned) width of 10: |%-10s|\n", "string4");
    ft_printf("(ft_2e) My ft_printf with a string as an argument |%1s| and then another |%2s| in the middle of a larger format string.\n", "__string5__", "_string6_");
    ft_printf("(ft_2f) My ft_printf with a string as an argument with a width of 2: |%2s|\n", "string7");
    ft_printf("(ft_2g) My ft_printf with a string _string_ and precision of three (should print \'str\'): |%.3s|\n", "string");
	ft_printf("(ft_2h) My ft_printf with a string _string_ and precision of three AND field-width of 5 (should print \'  str\'): |%5.3s|\n", "string");
    ft_printf("(ft_2i) My ft_printf with a string _string_ and precision of three AND field-width of -5 (should print \'str  \'): |%-5.3s|\n", "string");
    /*printf("(2a) printf with s conversion and field width 10: %10s\n", "Test.");
    printf("(2d) printf with s conversion and field width -10 (left-aligned): %-10s\n", "Test.");
    printf("(2f) printf with s conversion and field width 2: %2s\n", "Test.");
    printf("(2g) printf with a string _string_ and precision of three (should print \'str\'): %.3s\n", "string");
    printf("(2h) printf with a string _string_ and precision of three AND field-width of 5 (should print \'  str\'): %5.3s\n", "string");
    printf("(2i) printf with a string _string_ and precision of three AND field-width of -5 (should print \'str  \'): %-5.3s\n", "string");
    printf("(2k) printf with a string _string_ and precision of 3 (should print \'str\'): |%.3s|\n", "string");*/
    ft_printf("(ft_3a) ft_printf: -5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("(ft_3b) ft_printf: 5.3s LYDI == |%5.3s|\n", "LYDI");
    //printf("printf: %%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	//printf("printf: %%5.3s LYDI == |%5.3s|\n", "LYDI");
	ft_printf("(ft_2c) My ft_printf with a string as an argument with a width of 10: |%10s|\n", "string3");
    ft_printf("(ft_ARGHH) ft_printf: |%s|\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir");
    //ft_printf("(ft_3) ft_printf with a widechar string: %ls\n", s);
	//ft_putstr("Next one should be: ft_printf 4343: Percent conversion WITHOUT width and shit: |%|\n");
	//ft_printf("ft_printf: Percent conversion WITHOUT width and shit: |%%|\n"); //doesn't work?!
	//ft_printf("ft_printf 4343: Percent conversion WITHOUT width and shit: |%%|\n");
    //printf("printf: |%s|\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir");
	//printf("(3) Printf with a widechar string: %ls\n", s);
	//printf("printf: Percent conversion WITHOUT width and shit: |%%|\n");
	
}