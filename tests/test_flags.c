#include "ft_printf.h"    
#include "printf_tests.h"

/*
** void * printed in hexadecimal (as if by %#x or %#lx)
**
** To-do: account for l option.
*/

void    test_flags(void)
{
    int             i;
    double          d;
    char            c;
    short int       s;
    long int        l;
    long long int   ll;
    unsigned char            uc;
    unsigned short int       us;
    unsigned long int        ul;
    unsigned long long int   ull;
    
    i = 42;
    d = 42;
    c = 11;
    s = 12;
    l = 13;
    ll = 14;
    uc = 21;
    us = 22;
    ul = 23;
    ull = 24;
    ft_printf("\n=====FLAG TESTS=====\n");
    ft_printf("(ft_1a) Ft_printf with # flag and o conversion: %#o\n", i);
	ft_printf("(ft_1ab) Ft_printf with # and space flags and o conversion: %# o\n", i);
    ft_printf("(ft_1b) Ft_printf with # flag and x conversion: %#x\n", i);
    ft_printf("(ft_1c) Ft_printf with # flag and X conversion: %#X\n", i);
    ft_printf("(ft_1dALPHA) Ft_printf with # flag and f conversion and precision of 3: %#.3f\n", d);
    ft_printf("(ft_1dBETA) Ft_printf WITHOUT # flag and f conversion: %f\n", d);
	ft_printf("(ft_1e) Ft_printf with # flag and d conversion: %#d\n", i);
    printf("(1a) Printf with # flag and o conversion: %#o\n", i);
	printf("(1ab) Printf with # and space flags and o conversion: %# o\n", i);
    printf("(1b) Printf with # flag and x conversion: %#x\n", i);
    printf("(1c) Printf with # flag and X conversion: %#X\n", i);
    printf("(1dALPHA) Printf with # flag and f conversion and precision of 3: %#.3f\n", d);
    printf("(1dBETA) Printf WITHOUT # flag and f conversion: %f\n", d);
	printf("(1e) Printf with # flag and d conversion: %#d\n", i);
    ft_printf("\n");
    ft_printf("(ft_2a) ft_printf with + flag and d conversion: %+d\n", i);
    ft_printf("(ft_2b) ft_printf with + flag and o conversion: %+o\n", i);
    ft_printf("(ft_2c) ft_printf with + flag and f conversion: %+f\n", d);
    printf("(2a) printf with + flag and d conversion: %+d\n", i);
    printf("(2b) printf with + flag and o conversion: %+o\n", i);
    printf("(2c) printf with + flag and f conversion: %+f\n", d);
    ft_printf("\n");
    ft_printf("(ft_3a) ft_printf with ' ' flag and d conversion: |% d|\n", i);
    ft_printf("(ft_3b) ft_printf with ' ' flag and o conversion: |% o|\n", i);
    ft_printf("(ft_3c) ft_printf with ' ' flag and f conversion: |% f|\n", d);
    printf("(3a) printf with ' ' flag and d conversion: |% d|\n", i);
    printf("(3b) printf with ' ' flag and o conversion: |% o|\n", i);
    printf("(3c) printf with ' ' flag and f conversion: |% f|\n", d);
    ft_printf("\n");
    ft_printf("(ft_4a) ft_printf with hh flag and d conversion: %hhd\n", c);
    ft_printf("(ft_4b) ft_printf with h flag and d conversion: %hd\n", s);
    ft_printf("(ft_4c) ft_printf with l flag and d conversion: %ld\n", l);
    ft_printf("(ft_4d) ft_printf with ll flag and d conversion: %lld\n", ll);
    printf("(4a) printf with hh flag and d conversion: %hhd\n", c);
    printf("(4b) printf with hh flag and d conversion: %hd\n", s);
    printf("(4c) printf with l flag and d conversion: %ld\n", l);
    printf("(4d) printf with ll flag and d conversion: %lld\n", ll);
    ft_printf("\n");
    ft_printf("(ft_5a) ft_printf with hh flag and o conversion: %hho\n", c);
    ft_printf("(ft_5b) ft_printf with h flag and o conversion: %ho\n", s);
    ft_printf("(ft_5c) ft_printf with l flag and o conversion: %lo\n", l);
    ft_printf("(ft_5d) ft_printf with ll flag and o conversion: %llo\n", ll);
    printf("(5a) printf with hh flag and o conversion: %hho\n", c);
    printf("(5b) printf with hh flag and o conversion: %ho\n", s);
    printf("(5c) printf with l flag and o conversion: %lo\n", l);
    printf("(5d) printf with ll flag and o conversion: %llo\n", ll);
    ft_printf("\n");
    ft_printf("(ft_6a) ft_printf with hh flag and u conversion: %hhu\n", uc);
    ft_printf("(ft_6b) ft_printf with h flag and u conversion: %hu\n", us);
    ft_printf("(ft_6c) ft_printf with l flag and u conversion: %lu\n", ul);
    ft_printf("(ft_6d) ft_printf with ll flag and u conversion: %llu\n", ull);
    printf("(6a) printf with hh flag and u conversion: %hhu\n", uc);
    printf("(6b) printf with hh flag and u conversion: %hu\n", us);
    printf("(6c) printf with l flag and u conversion: %lu\n", ul);
    printf("(6d) printf with ll flag and u conversion: %llu\n", ull);
    ft_printf("\n");
    ft_printf("(ft_7a) ft_printf with hh flag and x conversion: %hhx\n", c);
    ft_printf("(ft_7b) ft_printf with h flag and x conversion: %hx\n", s);
    ft_printf("(ft_7c) ft_printf with l flag and x conversion: %lx\n", l);
    ft_printf("(ft_7d) ft_printf with ll flag and x conversion: %llx\n", ll);
    printf("(7a) printf with hh flag and x conversion: %hhx\n", c);
    printf("(7b) printf with hh flag and x conversion: %hx\n", s);
    printf("(7c) printf with l flag and x conversion: %lx\n", l);
    printf("(7d) printf with ll flag and x conversion: %llx\n", ll);
    ft_printf("\n");
    ft_printf("(ft_8a) ft_printf with hh flag and X conversion: %hhX\n", c);
    ft_printf("(ft_8b) ft_printf with h flag and X conversion: %hX\n", s);
    ft_printf("(ft_8c) ft_printf with l flag and X conversion: %lX\n", l);
    ft_printf("(ft_8d) ft_printf with ll flag and X conversion: %llX\n", ll);
    printf("(8a) printf with hh flag and X conversion: %hhX\n", c);
    printf("(8b) printf with hh flag and X conversion: %hX\n", s);
    printf("(8c) printf with l flag and X conversion: %lX\n", l);
    printf("(8d) printf with ll flag and X conversion: %llX\n", ll);
}