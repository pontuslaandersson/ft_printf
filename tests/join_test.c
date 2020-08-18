#include "ft_printf.h"
#include "printf_tests.h"

int     main(void)
{
	ft_printf("Get_width test 1; should give |0000000385|: |%010d|\n", 385); // Works!
	//printf("Get_width control 1; should give |0000000385|: |%010d|\n", 385);
	ft_printf("Get_width test 2; should give |       385|: |%10d|\n", 385); // Works!
	//printf("Get_width control 2; should give |       385|: |%10d|\n", 385);
	ft_printf("Get_width test 3e (10); should give |       str|: |%10s|\n", "str"); // Works!
	//printf("Get_width control 3e (10); should give |       str|: |%10s|\n", "str");
	ft_printf("Get_width test 3f (010); should give |0000000str|: |%010s|\n", "str"); // Works!
	//printf("Get_width control 3f (010); should give |0000000str|: |%010s|\n", "str");

	ft_printf("%c\n", 42); //  Works!
	ft_printf("%c\n", 65); //  Works!
	ft_printf("%c", 42); // Works!
	ft_printf("%c", 65); // Works!
	ft_printf("%%");  // Works!
	ft_printf("%%\n"); // Works!
	ft_printf("%c", 0); // Works!
	ft_printf("ft_printf: Percent conversion WITHOUT width and shit: |%%|\n");
	ft_printf("This shit has a %c (nul) in the middle.\n", 0);
	ft_printf("(ft_11) ft_printf (%%04.3i; this shit should ignore zero flag, print three numbers, and one leading space): |%04.3i|\n", 42); // Doesn't work!
	return (0);
}