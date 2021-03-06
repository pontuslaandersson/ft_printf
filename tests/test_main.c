#include "ft_printf.h"
#include "printf_tests.h"
#define BUFSIZE 9

void init_buf(char *buf, size_t size){
    int i;
    for(i=0; i<size; i++){
        buf[i] = i + '0'; // int to char conversion
    }
}

void print_buf(char *buf){
    int i;
    char c;
    for(i=0; i<BUFSIZE; i++){
        c = buf[i];
        if(c == '\0'){
            printf("\\0");

        }
        else{
            printf("%c", buf[i]);
        }
    }
    printf("\n");
}

int     main(void)
{
    void        *p_test;
    int         i;
    double      d;
    long int    l;
	char            c;
    short int       s;
    long long int   ll;
	char buf[BUFSIZE];

    i = 42;
    p_test = &i;
    d = 3.16000;
    l = 48;

	ft_printf("%");
    ft_printf("Ladies and gentlemen, bugs and malfunctions, brought to you by ft_printf, we give you, the FT_PRINTF TESTS!\n\n");
    /*ft_printf("(ft_22; the end ft_printf) ft_printf manages '%%%%' to %d %%. 1\n", 100);
	ft_printf("(ft_22; the end ft_printf) ft_printf manages '%%%%' to %d %%. 1\n", 100);
	ft_printf("(ft_22; the end ft_printf) ft_printf manages '%%%%' to %d %%. 1\n", 100); // No leaks in block!
	ft_printf("\n");*/
	//ft_printf("%5%");
    
	/*ft_printf("ft_printf: Percent conversion WITHOUT width and shit: |%%|\n");
	ft_printf("ft_printf 4343: Percent conversion WITHOUT width and shit: |%%|\n");*/
	
	//ft_printf("%d; conversion up front for ft_printf.\n", 42);
	//ft_printf("%04.3i (%%04.3i; should ignore zero flag, print three numbers, and one leading space)\n", 42);
	//ft_putstr("Next one should be: ft_printf 4343: Percent conversion WITHOUT width and shit: |%%|\n");

	ft_printf("Get_width test 1; should give |0000000385|: |%010d|\n", 385);
	printf("Get_width control 1; should give |0000000385|: |%010d|\n", 385);
	ft_printf("Get_width test 2; should give |       385|: |%10d|\n", 385);
	printf("Get_width control 2; should give |       385|: |%10d|\n", 385);
	ft_printf("Get_width test 3a (-10); should give |385       |: |%-10d|\n", 385);
	printf("Get_width control 3a (-10); should give |385       |: |%-10d|\n", 385);
	ft_printf("Get_width test 3b (-010); should give |385       |: |%-010d|\n", 385);
	printf("Get_width control 3b (-010); should give |385       |: |%-010d|\n", 385);
	ft_printf("Get_width test 3c (-010); should give |str       |: |%-010s|\n", "str");
	printf("Get_width control 3c (-010); should give |str       |: |%-010s|\n", "str");
	ft_printf("Get_width test 3d (-10); should give |str       |: |%-10s|\n", "str");
	printf("Get_width control 3d (-10); should give |str       |: |%-10s|\n", "str");
	ft_printf("Get_width test 3e (10); should give |       str|: |%10s|\n", "str");
	printf("Get_width control 3e (10); should give |       str|: |%10s|\n", "str");
	ft_printf("Get_width test 3f (010); should give |0000000str|: |%010s|\n", "str");
	printf("Get_width control 3f (010); should give |0000000str|: |%010s|\n", "str");
	printf("(0b) printf control with d conversion with ll flag (LLMAX): %llo\n", 9223372036854775807); // ft_printf output: (ft_0b) ft_printf with d conversion with ll flag (LLMAX): 777777777777777777777
	printf("(9e) printf control with x conversion with ll flag: %llx\n", 2147483645446845483);
	ft_printf("(ft_9g) ft_printf with x conversion with ll flag (ULLMAX): |%llx|\n", 18446744073709551615); //ffffffffffffffff
	//system("leaks test");
	//printf("(9g) printf control with x conversion with ll flag (ULLMAX): |%llx|\n", 18446744073709551615);  //ffffffffffffffff
    ft_printf("(ft_11) ft_printf (%%04.3i; should ignore zero flag, print three numbers, and one leading space): |%04.3i|\n", 42); // No leaks in this block!
	/*c = 11;
    s = 12;
    l = 13;
    ll = 14;
	ft_printf("(ft_8a) ft_printf with hh flag and X conversion: %10hhX\n", c);
    ft_printf("(ft_8b) ft_printf with h flag and X conversion: %10hX\n", s);
    ft_printf("(ft_8c) ft_printf with l flag and X conversion: %l10X\n", l);
    ft_printf("(ft_8d) ft_printf with ll flag and X conversion: %10llX\n", ll);*/
	test_strings(); // No leaks!
    test_char(); // No leaks!
    test_diouxX(); // No leaks!
    test_pointer(); // No leaks!
    test_f();
    test_flags(); // No leaks!
    //ft_printf("\n");
    //test_returns(); // No leaks!
	//ft_printf("%s.\n", "(ft_1a) My ft_printf with an unformatted string, as an %s conversion");
	//ft_printf("%s|\n", "(ft_1a) My ft_printf with an unformatted string, as an %s conversion");
	//ft_printf("%f.", 3.16);
	//ft_printf("%s!", "Ceci n'est toujours pas un exercice !"); // Can't do this at home!
	//printf("%s!", "Ceci n'est toujours pas un exercice !");
	//ft_printf("%c\n", 42); // Works!
	//ft_printf("%c\n", 65); // Work!
	//ft_printf("%c", 42); // Work!
	//ft_printf("%c", 65); // Work!
	//ft_printf("%%"); // Works!
	//test_failed();
	//ft_printf("Get_width test 2; should give |       385|: |%10d|\n", 385);
	//ft_printf("Get_width test 3a (-10); should give |385       |: |%-10d|\n", 385);
	//ft_printf("%10c", -0);
      //expected output : " "
      //your output     : "��;R�"

	//ft_printf("%-10c", 0);
	/*      expected output : " "
		your output     : "��;R�"
		expected (nonprintable as hex) : "\x00"
		actual   (nonprintable as hex) : "\x84\x89;R\xff\x7f"*/
	//ft_printf("This should end with a newline: |%10c|\n", -0);
	//ft_printf("This should end with a newline: %-10c\n", 0);
	//ft_printf("%%d 0000042 == |%d|\n", 0000042);
	/*int r00 = 0;
	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);
	ft_snprintf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);*/

	printf("Now for some zeros.\n");
	ft_printf("%f\n", 0.);
	printf("%f\n", -0.);
	ft_printf("%f\n", -0.);
	ft_printf("F %*s\n", 10, "test");
	printf("0 %*s\n", 10, "test");
	ft_printf("F %%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	printf("0 %%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("F %% *.5i 42 == |% *.5i|\n", 4, 42);
	printf("0 %% *.5i 42 == |% *.5i|\n", 4, 42);

	/*printf("O %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);
	printf("O %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);
	ft_printf("F %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);*/
	printf("O 10.5 = %.0f\n", 10.5);
	ft_printf("F 10.5 = %.0f\n", 10.5);
	printf("O 11.5 = %.0f\n", 11.5);
	ft_printf("F 11.5 = %.0f\n", 11.5);
	printf("O 12.5 = %.0f\n", 12.5);
	ft_printf("F 12.5 = %.0f\n", 12.5);
	/*printf("O %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", 11.05, 11.15, 11.25, 11.35, 11.45, 11.55, 11.65, 11.75, 11.85, 11.95);
	printf("O %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f\n", 11.05, 11.15, 11.25, 11.35, 11.45, 11.55, 11.65, 11.75, 11.85, 11.95);
	ft_printf("F %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f %-5.17f\n", 11.05, 11.15, 11.25, 11.35, 11.45, 11.55, 11.65, 11.75, 11.85, 11.95);
	ft_printf("F %.1f\n", 10.25);
	printf("0 %.1f\n", 10.25);*/
	//ft_printf("%%d 0000042 == |%d|", 42);
	//ft_printf("%%d == |%d|", '	');
	//ft_printf("%%d 0000042 == |%d|", 10);
	//test_leaks();
	init_buf(buf, BUFSIZE);
    print_buf(buf);

	/*init_buf(buf, BUFSIZE);
    ft_snprintf(buf, BUFSIZE, "turtle");
    print_buf(buf);*/
	// hello there! == 12 characters, > BUFSIZE
	printf("==============MINE!==================");
    init_buf(buf, BUFSIZE);
    ft_snprintf(buf, BUFSIZE, "hello there!");
    print_buf(buf);

    // turtle == 6 charaters, < BUFSIZE
    init_buf(buf, BUFSIZE);
    ft_snprintf(buf, BUFSIZE, "turtle");
    print_buf(buf);

    // 2222220 == 7 charaters, > 5
    init_buf(buf, BUFSIZE);
    ft_snprintf(buf, 5, "%d", 222222 * 10);
    print_buf(buf);

	/*if(ft_snprintf(buf, BUFSIZE, "hello") >= BUFSIZE){
        printf("%s\n", buf);
    }

    if(ft_snprintf(buf, BUFSIZE, "An extremely long string") >= BUFSIZE){
        printf("buf: %s\n", buf);
    }

    if(ft_snprintf(buf, BUFSIZE, "0%d", 123456789) >= BUFSIZE){
        printf("buf: %s\n", buf);
    }*/

	printf("==============THE REAL ONE==================");
	init_buf(buf, BUFSIZE);
    snprintf(buf, BUFSIZE, "hello there!");
    print_buf(buf);

    // turtle == 6 charaters, < BUFSIZE
    init_buf(buf, BUFSIZE);
    snprintf(buf, BUFSIZE, "turtle");
    print_buf(buf);

    // 2222220 == 7 charaters, > 5
    init_buf(buf, BUFSIZE);
    snprintf(buf, 5, "%d", 222222 * 10);
    print_buf(buf);

	/*init_buf(buf, BUFSIZE);
	if(snprintf(buf, BUFSIZE, "hello") >= BUFSIZE){
        printf("%s\n", buf);
    }

	init_buf(buf, BUFSIZE);
    if(snprintf(buf, BUFSIZE, "An extremely long string") >= BUFSIZE){
        printf("buf: %s\n", buf);
    }

	init_buf(buf, BUFSIZE);
    if(snprintf(buf, BUFSIZE, "0%d", 123456789) >= BUFSIZE){
        printf("buf: %s\n", buf);
    }*/

	/*
	** Segfault!
	** Should be: 'Hello World    '\n'              b',
	** getting width from "-0" and missing the star,
	** which should still account for the '-' given, while
	** anything but a '0' won't work with the real printf.
	** SOLUTION: '-' has to be parsed separately;
	** -* and a negative argument has to *not* result in a
	** positive width, but remains negative.
	*/
	char b = 'b';
	char *str = "Hello world";
	printf("'%-0*s'\n'%15c'\n", 15, str, c);
	//ft_printf("'%-0*s'\n'%15c'\n", 15, str, c);
	long long int lli = 55165;
	int	in = 3;
	/*
	** ll flag with d conversion causing timeout.
	** (%d conversion works just fine.)
	*/
	ft_printf("'%-10.5lld'\n'%-10.5d'\n", lli, in);
 	printf("'%-10.5lld'\n'%-10.5d'\n", lli, in);
	printf("real: %f\n", +432232342.019384);
	ft_printf("ft: %f\n", +432232342.019384); // This is very, very slow. Why? Update: No longer slow in updated printf.
	printf("0 - .22: %.22f\n", +432232342.0193845684963);
	ft_printf("f - .22: %.22f\n", +432232342.0193845684963);
	printf("0 - .20: %.20f\n", +432232342.01234567890123456789012);
	ft_printf("f - .20: %.20f\n", +432232342.01234567890123456789012);
	//ft_printf("f: %.21f\n", +432232342.012345678901234567890126549456516868); // With precision of more than .20 we get errors.
	//ft_printf("f: %.22f\n", +432232342.0123456789012345678901221); // With precision of more than .20 we get errors, regardless of the actual number.
	//printf("0: %.20f\n", +432232342.01234567890123); 
	//ft_printf("f: %.20f\n", +432232342.01234567890123); // .20, but float smaller than 20, still works. 

    return (0);
}
