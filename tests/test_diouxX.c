#include "ft_printf.h"    
#include "printf_tests.h"

//d (int to signed decimal notation; default precision is 1)
//i (as d) hh(signed char or unsigned char argument, or a pointer to a signed char argument.), 
//h (short int/unsigned short in, pointer to short int), l (long int, unsigned long int, wint_t, pointer to wchar_t)
// ll (long long int/unsigned long long int, pointer to long long int; also q in older code)

/*
** To-do: account for l, h, ll options.
*/

void    test_diouxX(void)
{
    void            *p_test;
    int             i;
    unsigned int    j;
    double          d;
    long int        l;

    i = 42;
    j = 43;
    p_test = &i;
    d = 3.16000;
    l = 48;
    ft_printf("\n====diouxX TESTS====\n");
	printf("(0a1) printf control with o conversion with l flag (ULMAX): %lo\n", 4294967295);
	ft_printf("(ft_0a1) ft_printf with o conversion with l flag (ULMAX): %lo\n", 4294967295);
	printf("(0a2) printf control with o conversion with l flag (ULMIN): %lo\n", 0);
	ft_printf("(ft_0a2) ft_printf with o conversion with l flag (ULMIN): %lo\n", 0);
	printf("(0b) printf control with o conversion with ll flag (ULLMAX): %llo\n", 18446744073709551615);
    ft_printf("(ft_0b) ft_printf with o conversion with ll flag (ULLMAX): %llo\n", 18446744073709551615);
	printf("(0b) printf control with o conversion with ll flag (ULLMIN): %llo\n", 0);
	ft_printf("(ft_0b) ft_printf with o conversion with ll flag (ULLMIN): %llo\n", 0);
	printf("(0c) printf control with o conversion with l flag (ULMAX - 1): %lo\n", 4294967294);
	ft_printf("(0c) ft_printf with o conversion with l flag (ULMAX - 1): %lo\n", 4294967294);
    printf("(0d) printf control with o conversion with ll flag (ULLMAX - 1): %llo\n", 18446744073709551614);
    ft_printf("(ft_0d) ft_printf with o conversion with ll flag (ULLMAX - 1): %llo\n", 18446744073709551614);
	/*printf("(0a1) printf with d conversion with l flag (LMAX): %lo\n", 2147483647);
	printf("(0a2) printf with d conversion with l flag (LMIN): %lo\n", -2147483647);
    printf("(0b) printf with d conversion with ll flag (LLMAX): %llo\n", 9223372036854775807);
	printf("(0b) printf with d conversion with ll flag (LLMIN): %llo\n", -9223372036854775807);
	printf("(0c) printf with d conversion with l flag (LMAX - 1): %lo\n", 2147483646);
    printf("(0d) printf with d conversion with ll flag (LLMAX - 1): %llo\n", 18446744073709551614); // NO LEAKS!*/
    //printf("(6a) Printf with d conversion: |%d|\n", i);
    //printf("(6x) Printf with d conversion, zero-padded to 10: |%010d|\n", i);
    //printf("(6xx) Printf with d conversion, zero-padded to 10 of int = 4242: |%010d|\n", 4242);
    //printf("(6xxxx) Printf with d conversion, with precision = 10 (behaves as zero padding), of int = 4242: |%.10d|\n", 4242);
    //printf("(6xxxxx) Printf with d conversion, with precision = 8 (behaves as zero padding) AND field width 10, of int = 4242: |%10.8d|\n", 4242);
    ft_printf("(ft_6a) Ft_printf with d conversion: |%d|\n", i);
	ft_printf("(ft_6b) Ft_printf with d conversion, width = 10: |%10d|\n", i);
	ft_printf("(ft_6c) Ft_printf with d conversion, width = -10: |%-10d|\n", i);
	ft_printf("(ft_6c) Ft_printf with d conversion, width = -010: |%-010d|\n", i);
	printf("(6c) printf with d conversion, width = -010: |%-010d|\n", i);
    ft_printf("(ft_6x) Ft_printf with d conversion, zero-padded to 10: |%010d|\n", i);
    ft_printf("(ft_6xx) Ft_printf with d conversion, zero-padded to 10 of int = 4242: |%010d|\n", 4242);
    ft_printf("(ft_6xxxx) Ft_printf with d conversion, with precision = 10 (behaves as zero padding), of int = 4242: |%.10d|\n", 4242);
    ft_printf("(ft_6xxxxx) Ft_printf with d conversion, with precision = 6 (behaves as zero padding) AND field width 10, of int = 4242: |%10.8d|\n", 4242); // NO LEAKS!
    
	
	ft_printf("(ft_7a) Ft_printf with o conversion: %o\n", i);
    ft_printf("(ft_8a) Ft_printf with u conversion: %u\n", j);


    //ft_printf("(ft_9a) Ft_printf with x conversion: %x\n", i);
    //ft_printf("(ft_10a) Ft_printf with X conversion: %X\n", i);
    //printf("(6b) Printf with d conversion with hh flag: %hhd\n", i);
    //printf("(6c) Printf with d conversion with h flag: %hd\n", i);
    //printf("(6d) Printf with d conversion with l flag: %ld\n", 21474836454468);
    //printf("(6e) Printf with d conversion with ll flag: %lld\n", 9223372036854775807);
	//printf("(6xx) Printf with d conversion, zero-padded to 10 of int = 4242: |%010d|\n", 4242); 
    //(7) o (octal) hh, h, l and ll
	ft_printf("(ft_7a) ft_printf with o conversion: %o\n", i);
    ft_printf("(ft_7b) ft_printf with o conversion with hh flag: %hho\n", i);
    ft_printf("(ft_7c) ft_printf with o conversion with h flag: %ho\n", i);
    ft_printf("(ft_7d) ft_printf with o conversion with l flag: %lo\n", 21474836454468);
    ft_printf("(ft_7e) ft_printf with o conversion with ll flag: %llo\n", 9223372036854775807);
	ft_printf("(ft_7f) ft_printf with o conversion with l flag (ULMAX): %lo\n", 4294967295);
    ft_printf("(ft_7g) ft_printf with o conversion with ll flag (ULLMAX): %llo\n", 18446744073709551615);
	ft_printf("(ft_7h) ft_printf with o conversion with l flag (ULMAX - 1): %lo\n", 4294967294);
    ft_printf("(ft_7i) ft_printf with o conversion with ll flag (ULLMAX - 1): %llo\n", 18446744073709551614);
    /*printf("(7a) Printf with o conversion: %o\n", i);
    printf("(7b) Printf with o conversion with hh flag: %hho\n", i);
    printf("(7c) Printf with o conversion with h flag: %ho\n", i);
    printf("(7d) Printf with o conversion with l flag: %lo\n", 21474836454468);
    printf("(7e) Printf with o conversion with ll flag: %llo\n", 9223372036854775807);
	printf("(7f) printf with o conversion with l flag (ULMAX): %lo\n", 4294967295);
    printf("(7g) printf with o conversion with ll flag (ULLMAX): %llo\n", 18446744073709551615);
	printf("(7h) printf with o conversion with l flag (ULMAX - 1): %lo\n", 4294967294);
    printf("(7i) printf with o conversion with ll flag (ULLMAX - 1): %llo\n", 18446744073709551614); // NO LEAKS!*/
	ft_printf("(ft_8a) ft_printf with lu conversion: %lu\n", l);
    ft_printf("(ft_8b) ft_printf with u conversion with hh flag: %hhu\n", i);
    ft_printf("(ft_8c) ft_printf with u conversion with h flag: %hu\n", i);
    ft_printf("(ft_8d) ft_printf with u conversion with l flag (ULMAX): %lu\n", 4294967295);
    ft_printf("(ft_8e) ft_printf with u conversion with ll flag (ULLMAX): %llu\n", 18446744073709551615);
	ft_printf("(ft_8d) ft_printf with u conversion with l flag (ULMAX - 1): %lu\n", 4294967294);
    ft_printf("(ft_8e) ft_printf with u conversion with ll flag (ULLMAX - 1): %llu\n", 18446744073709551614);
	ft_printf("(ft_8d) ft_printf with u conversion with l flag: %lu\n", 4294967200);
    ft_printf("(ft_8e) ft_printf with u conversion with ll flag: %llu\n", 18446744073709551200);
    /*printf("(8a) Printf with lu conversion: %lu\n", l);
    printf("(8b) Printf with u conversion with hh flag: %hhu\n", i);
    printf("(8c) Printf with u conversion with h flag: %hu\n", i);
    printf("(8d) Printf with u conversion with l flag: %lu\n", 4294967295);
    printf("(8e) Printf with u conversion with ll flag: %llu\n", 18446744073709551615); // NO LEAKS!*/
    ft_printf("(ft_9a) ft_printf with x conversion: %x\n", i);
    ft_printf("(ft_9b) ft_printf with x conversion with hh flag: %hhx\n", i);
    ft_printf("(ft_9c) ft_printf with x conversion with h flag: %hx\n", i);
    ft_printf("(ft_9d) ft_printf with x conversion with l flag: %lx\n", 21474836454468);
    ft_printf("(ft_9e) ft_printf with x conversion with ll flag: %llx\n", 2147483645446845483);
	ft_printf("(ft_9f) ft_printf with x conversion with l flag (ULMAX): %lx\n", 4294967295);
    ft_printf("(ft_9g) ft_printf with x conversion with ll flag (ULLMAX): %llx\n", 18446744073709551615);
	ft_printf("(ft_9h) ft_printf with x conversion with l flag (ULMAX - 1): %lx\n", 4294967294);
    ft_printf("(ft_9i) ft_printf with x conversion with ll flag (ULLMAX - 1): %llx\n", 18446744073709551614);

	/*printf("(9a) Printf with x conversion: %x\n", i);
    printf("(9b) Printf with x conversion with hh flag: %hhx\n", i);
    printf("(9c) Printf with x conversion with h flag: %hx\n", i);
    printf("(9d) Printf with x conversion with l flag: %lx\n", 21474836454468);
    printf("(9e) Printf with x conversion with ll flag: %llx\n", 2147483645446845483);
	printf("(9f) printf with x conversion with l flag (ULMAX): %lx\n", 4294967295);
    printf("(9g) printf with x conversion with ll flag (ULLMAX): %llx\n", 18446744073709551615);
	printf("(9h) printf with x conversion with l flag (ULMAX - 1): %lx\n", 4294967294);
    printf("(9i) printf with x conversion with ll flag (ULLMAX - 1): %llx\n", 18446744073709551614); // NO LEAKS!*/
    ft_printf("(ft_10a) ft_printf with X conversion: %X\n", i);
    ft_printf("(ft_10b) ft_printf with X conversion with hh flag: %hhX\n", i);
    ft_printf("(ft_10c) ft_printf with X conversion with h flag: %hX\n", i);
    ft_printf("(ft_10d) ft_printf with X conversion with l flag: %lX\n", 21474836454468);
    ft_printf("(ft_10e) ft_printf with X conversion with ll flag: %llX\n", 2147483645446845483);
	ft_printf("(ft_10f) ft_printf with X conversion with l flag (ULMAX): %lX\n", 4294967295);
    ft_printf("(ft_10g) ft_printf with X conversion with ll flag (ULLMAX): %llX\n", 18446744073709551615);
	ft_printf("(ft_10h) ft_printf with X conversion with l flag (ULMAX - 1): %lX\n", 4294967294);
	ft_printf("(ft_10i) ft_printf with X conversion with ll flag (ULLMAX - 1): %llX\n", 18446744073709551614);

	/*printf("(10a) Printf with X conversion: %x\n", i);
    printf("(10b) Printf with X conversion with hh flag: %hhX\n", i);
    printf("(10c) Printf with X conversion with h flag: %hX\n", i);
    printf("(10d) Printf with X conversion with l flag: %lX\n", 21474836454468);
    printf("(10e) Printf with X conversion with ll flag: %llX\n", 2147483645446845483);
	printf("(10f) printf with X conversion with l flag (ULMAX): %lX\n", 4294967295);
    printf("(10g) printf with X conversion with ll flag (ULLMAX): %llX\n", 18446744073709551615);
	printf("(10h) printf with X conversion with l flag (ULMAX - 1): %lX\n", 4294967294);
    printf("(10i) printf with X conversion with ll flag (ULLMAX - 1): %llX\n", 18446744073709551614);*/ // NO LEAKS!
    ft_printf("(ft_11) ft_printf (%%04.3i; should ignore zero flag, print three numbers, and one leading space): |%04.3i|\n", 42); // No leaks!
    //printf("(11) printf: |%04.3i|\n", 42);
}
