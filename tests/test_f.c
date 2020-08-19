#include "ft_printf.h"    
#include "printf_tests.h"

/*
** f: Print floating point value.
*/

void    test_f(void)
{
    double      d;
    long double ld;
    float       f;
    
    d = 3.16000;
    ld = 13.1313;
    f = 3.11111111111111111111;
    ft_printf("\n=====FLOAT TESTS====\n");
    printf("(11a) Printf with f conversion: |%f|\n", d);
    printf("(11b) Printf with f conversion and precision of 2: |%.2f|\n", d);
    printf("(11c) Printf with f conversion, field width of 10, and precision of 2: |%10.2f|\n", d);
    printf("(11d) Printf with f conversion, negative field width of 10, and precision of 2: |%-10.2f|\n", d);
    printf("(11e) Printf with f conversion and precision of 1: |%.1f|\n", d);
    printf("(11fa) Printf with f conversion and precision of NOTHING (\".\"): |%.f|\n", d);
	printf("(11fb) Printf with f conversion and precision not given (default = 6): |%f|\n", d);
    printf("(11g) Printf with f conversion of d = 3.51 and precision precision of NOTHING (\".\"): |%.f|\n", 3.51);
    printf("(11h) Printf with f conversion of d = 3.51 and precision of 0: |%.0f|\n", 3.51);
    printf("(11h) Printf with f conversion of d = 3.51 and precision of 01: |%.01f|\n", 3.51);
    ft_printf("\n");
    ft_printf("(ft_11a) Ft_rintf with f conversion: |%f|\n", d);
    ft_printf("(ft_11b) Ft_printf with f conversion and precision of 2: |%.2f|\n", d);
    ft_printf("(ft_11c) Ft_printf with f conversion, field width of 10, and precision of 2: |%10.2f|\n", d);
    ft_printf("(ft_11d) Ft_printf with f conversion, negative field width of 10, and precision of 2: |%-10.2f|\n", d);
    ft_printf("(ft_11e) Ft_printf with f conversion and precision of 1: |%.1f|\n", d);
    ft_printf("(ft_11fa) Ft_printf with f conversion and precision of NOTHING (\".\"): |%.f|\n", d);
    ft_printf("(ft_11fb) Ft_printf with f conversion and precision not given (default = 6): |%f|\n", d);
    ft_printf("(ft_11g) Ft_printf with f conversion of d = 3.51 and precision of NOTHING (\".\"): |%.f|\n", 3.51);
    ft_printf("(ft_11h) Ft_printf with f conversion of d = 3.51 and precision of 0: |%.0f|\n", 3.51);
    ft_printf("(ft_11h) Ft_printf with f conversion of d = 3.51 and precision of 01: |%.01f|\n", 3.51);

    ft_printf("\n");

    ft_printf("(ft_17a) Ft_printf with f conversion and precision of 2, 42.1: |%.2f|\n", 42.1);
    ft_printf("(ft_17b) Ft_printf with f conversion and precision of 2, 42.2: |%.2f|\n", 42.2);
    ft_printf("(ft_17c) Ft_printf with f conversion and precision of 2, 42.3: |%.2f|\n", 42.3);
    ft_printf("(ft_17d) Ft_printf with f conversion and precision of 2, 42.4: |%.2f|\n", 42.4);
    ft_printf("(ft_17e) Ft_printf with f conversion and precision of 2, 42.5: |%.2f|\n", 42.5);
    ft_printf("(ft_17f) Ft_printf with f conversion and precision of 2, 42.6: |%.2f|\n", 42.6);
    ft_printf("(ft_17g) Ft_printf with f conversion and precision of 2, 42.7: |%.2f|\n", 42.7);
    ft_printf("(ft_17h) Ft_printf with f conversion and precision of 2, 42.8: |%.2f|\n", 42.8);
    ft_printf("(ft_17i) Ft_printf with f conversion and precision of 2, 42.9: |%.2f|\n", 42.9);

    printf("(17a) printf with f conversion and precision of 2, 42.1: |%.2f|\n", 42.1);
    printf("(17b) printf with f conversion and precision of 2, 42.2: |%.2f|\n", 42.2);
    printf("(17c) printf with f conversion and precision of 2, 42.3: |%.2f|\n", 42.3);
    printf("(17d) printf with f conversion and precision of 2, 42.4: |%.2f|\n", 42.4);
    printf("(17e) printf with f conversion and precision of 2, 42.5: |%.2f|\n", 42.5);
    printf("(17f) printf with f conversion and precision of 2, 42.6: |%.2f|\n", 42.6);
    printf("(17g) printf with f conversion and precision of 2, 42.7: |%.2f|\n", 42.7);
    printf("(17h) printf with f conversion and precision of 2, 42.8: |%.2f|\n", 42.8);
    printf("(17i) printf with f conversion and precision of 2, 42.9: |%.2f|\n", 42.9);

    ft_printf("\n");

    ft_printf("(ft_17a) Ft_printf with f conversion and precision of 3, 42.1: |%.3f|\n", 42.1);
    ft_printf("(ft_17b) Ft_printf with f conversion and precision of 3, 42.2: |%.3f|\n", 42.2);
    ft_printf("(ft_17c) Ft_printf with f conversion and precision of 3, 42.3: |%.3f|\n", 42.3);
    ft_printf("(ft_17d) Ft_printf with f conversion and precision of 3, 42.4: |%.3f|\n", 42.4);
    ft_printf("(ft_17e) Ft_printf with f conversion and precision of 3, 42.5: |%.3f|\n", 42.5);
    ft_printf("(ft_17f) Ft_printf with f conversion and precision of 3, 42.6: |%.3f|\n", 42.6);
    ft_printf("(ft_17g) Ft_printf with f conversion and precision of 3, 42.7: |%.3f|\n", 42.7);
    ft_printf("(ft_17h) Ft_printf with f conversion and precision of 3, 42.8: |%.3f|\n", 42.8);
    ft_printf("(ft_17i) Ft_printf with f conversion and precision of 3, 42.9: |%.3f|\n", 42.9);

    printf("(17a) printf with f conversion and precision of 3, 42.1: |%.3f|\n", 42.1);
    printf("(17b) printf with f conversion and precision of 3, 42.2: |%.3f|\n", 42.2);
    printf("(17c) printf with f conversion and precision of 3, 42.3: |%.3f|\n", 42.3);
    printf("(17d) printf with f conversion and precision of 3, 42.4: |%.3f|\n", 42.4);
    printf("(17e) printf with f conversion and precision of 3, 42.5: |%.3f|\n", 42.5);
    printf("(17f) printf with f conversion and precision of 3, 42.6: |%.3f|\n", 42.6);
    printf("(17g) printf with f conversion and precision of 3, 42.7: |%.3f|\n", 42.7);
    printf("(17h) printf with f conversion and precision of 3, 42.8: |%.3f|\n", 42.8);
    printf("(17i) printf with f conversion and precision of 3, 42.9: |%.3f|\n", 42.9);

    ft_printf("\n");

    printf("(17a) printf with f conversion and precision of 3, 42.1: |%.3f|\n", 42.1);
    printf("(17b) printf with f conversion and precision of 3, 42.2: |%.3f|\n", 42.2);
    printf("(17c) printf with f conversion and precision of 3, 42.3: |%.3f|\n", 42.3);
    printf("(17d) printf with f conversion and precision of 3, 42.4: |%.3f|\n", 42.4);
    printf("(17e) printf with f conversion and precision of 3, 42.5: |%.3f|\n", 42.5);
    printf("(17f) printf with f conversion and precision of 3, 42.6: |%.3f|\n", 42.6);
    printf("(17g) printf with f conversion and precision of 3, 42.7: |%.3f|\n", 42.7);
    printf("(17h) printf with f conversion and precision of 3, 42.8: |%.3f|\n", 42.8);
    printf("(17i) printf with f conversion and precision of 3, 42.9: |%.3f|\n", 42.9);ft_printf("\n");

    ft_printf("\n");


    printf("(18a) printf with f conversion of negative number and precision of 3: |%.3f|\n", -89465.1);
    printf("(18b) printf with f conversion of negative number and precision of 3: |%.3f|\n", -68443.2);
    printf("(18c) printf with f conversion of negative number and precision of 3: |%.3f|\n", -8944.3);
    printf("(18d) printf with f conversion of negative number and precision of 3: |%.3f|\n", -651.4);
    printf("(18e) printf with f conversion of negative number and precision of 3: |%.3f|\n", -65454.5);
    printf("(18f) printf with f conversion of negative number and precision of 3: |%.3f|\n", -231.6);
    printf("(18g) printf with f conversion of negative number and precision of 3: |%.3f|\n", -53.7);
    printf("(18h) printf with f conversion of negative number and precision of 3: |%.3f|\n", -684.8);
    printf("(18i) printf with f conversion of negative number and precision of 3: |%.3f|\n", -6841.9);

    ft_printf("(ft_18a) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -89465.1);
    ft_printf("(ft_18b) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -68443.2);
    ft_printf("(ft_18c) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -8944.3);
    ft_printf("(ft_18d) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -651.4);
    ft_printf("(ft_18e) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -65454.5);
    ft_printf("(ft_18f) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -231.6);
    ft_printf("(ft_18g) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -53.7);
    ft_printf("(ft_18h) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -684.8);
    ft_printf("(ft_18i) ft_printf with f conversion of negative number and precision of 3: |%.3f|\n", -6841.9);

    /*ft_printf("(ft_19) Ft_printf with f conversion and precision of 2, 42.563: |%.2f|\n", 42.563);
    ft_printf("(ft_19) Ft_printf with f conversion and precision of 2, 42.565: |%.2f|\n", 42.565);
	printf("(19) printf control with f conversion and precision of 2, 42.563: |%.2f|\n", 42.563);
    printf("(19) printf control with f conversion and precision of 2, 42.565: |%.2f|\n", 42.565);*/
    
    printf("(20a) printf with f conversion of long double and precision of 3: |%.3Lf|\n", ld);

    ft_printf("(ft_20a) ft_printf with f conversion of long double and precision of 3: |%.3Lf|\n", ld);


    ft_printf("(ft_21a) ft_printf with 16 decimals (3.11111111111111111111): |%.16f|\n", 3.11111111111111111111);
    printf("(21a) printf with 16 decimals (3.11111111111111111111): |%.16f|\n", 3.11111111111111111111);
    ft_printf("(ft_21b) ft_printf with 16 decimals (3.16000): |%.16f|\n", d);
    printf("(21b) printf with 16 decimals (3.16000): |%.16f|\n", d);
    ft_printf("(ft_21c) ft_printf with 16 decimals (3.11111111111111111111): |%.16lf|\n", f);
    printf("(21c) printf with 16 decimals (3.11111111111111111111): |%.16lf|\n", f);
	ft_printf("(ft_21d) ft_printf with 16 decimals (13.1313): |%.16Lf|\n", ld);
    printf("(21d) printf with 16 decimals (13.1313): |%.16Lf|\n", ld);
    printf("\n");
    printf("printf with negative 0 in f conversion: |%f|\n", f);
    ft_printf("ft_printf with negative 0 in f conversion: |%f|\n", f);
    printf("printf with REGULAR 0 in f conversion: |%f|\n", f);
    ft_printf("ft_printf with REGULAR 0 in f conversion: |%f|\n", f);
    printf("\n");
  }