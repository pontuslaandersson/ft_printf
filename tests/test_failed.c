#include "ft_printf.h"
#include "printf_tests.h"

void    test_failed(void)
{
	ft_printf("========FAILED THIS SHIT========\n");
	ft_printf("%c", 42);
      //expected output : "*"
      //your output     : "*���"

	ft_printf("%10c", -0);
      //expected output : " "
      //your output     : "��;R�"

	ft_printf("%-10c", 0);
	/*      expected output : " "
		your output     : "��;R�"
		expected (nonprintable as hex) : "\x00"
		actual   (nonprintable as hex) : "\x84\x89;R\xff\x7f"*/

	ft_printf("%c", 'l');
	/*      expected output : "l"
		your output     : "l ��"
		expected (nonprintable as hex) : "l"
		actual   (nonprintable as hex) : "l \x02\xf0\xbd\xdf\x7f"*/

	ft_printf("%c", 'y');
	/*      expected output : "y"
		your output     : "y ���"
		expected (nonprintable as hex) : "y"
		actual   (nonprintable as hex) : "y \x02\x80\xc0\xdf\x7f"*/

	ft_printf("%c", ' ');
	/*      expected output : " "
		your output     : " ���"
		expected (nonprintable as hex) : " "
		actual   (nonprintable as hex) : " \xb0\x02\xe0\xbd\xdf\x7f"*/

	ft_printf("%c", 'e');
	/*      expected output : "e"
		your output     : "eP���"
		expected (nonprintable as hex) : "e"
		actual   (nonprintable as hex) : "eP\x02\x80\xc0\xdf\x7f"*/

	ft_printf("%c", 's');
	/*      expected output : "s"
		your output     : "s���"
		expected (nonprintable as hex) : "s"
		actual   (nonprintable as hex) : "s\xe0\x02\xe0\xbd\xdf\x7f"*/

	ft_printf("%c", 't');
	/*      expected output : "t"
		your output     : "t��;R�"
		expected (nonprintable as hex) : "t"
		actual   (nonprintable as hex) : "t\x84\x89;R\xff\x7f"*/

	ft_printf("%c", ' ');
	/*      expected output : " "
		your output     : " ��"
		expected (nonprintable as hex) : " "
		actual   (nonprintable as hex) : " \x10\x03\xe0\xbd\xdf\x7f"*/

	ft_printf("%c", 'f');
	/*      expected output : "f"
		your output     : "f��;R�"
		expected (nonprintable as hex) : "f"
		actual   (nonprintable as hex) : "f\x84\x89;R\xff\x7f"*/

	ft_printf("%c", 'a');
	/*      expected output : "a"
		your output     : "a��;R�"
		expected (nonprintable as hex) : "a"
		actual   (nonprintable as hex) : "a\x84\x89;R\xff\x7f"*/

	ft_printf("%c", 'n');
	/*      expected output : "n"
		your output     : "n��;R�"
		expected (nonprintable as hex) : "n"
		actual   (nonprintable as hex) : "n\x84\x89;R\xff\x7f"*/

	ft_printf("%c", 't');
	/*      expected output : "t"
		your output     : "t ���"
		expected (nonprintable as hex) : "t"
		actual   (nonprintable as hex) : "t \x02\x90\xc0\xdf\x7f"*/

	ft_printf("%c", 'a');
	/*      expected output : "a"
		your output     : "ac"
		expected (nonprintable as hex) : "a"
		actual   (nonprintable as hex) : "ac"*/

	ft_printf("%c", 's');
	/*      expected output : "s"
		your output     : "sP���"
		expected (nonprintable as hex) : "s"
		actual   (nonprintable as hex) : "sP\x02\x90\xc0\xdf\x7f"*/

	ft_printf("%c", 't');
	/*      expected output : "t"
		your output     : "tP��"
		expected (nonprintable as hex) : "t"
		actual   (nonprintable as hex) : "tP\x02\xf0\xbd\xdf\x7f"*/

	ft_printf("%c", 'i');
	/*      expected output : "i"
		your output     : "ip2���"
		expected (nonprintable as hex) : "i"
		actual   (nonprintable as hex) : "ip2\xc0\xbd\xdf\x7f"*/

	ft_printf("%c", 'q');
	/*      expected output : "q"
		your output     : "q����"
		expected (nonprintable as hex) : "q"
		actual   (nonprintable as hex) : "q\x80\x02\x90\xc0\xdf\x7f"*/

	ft_printf("%c", 'u');
	/*      expected output : "u"
		your output     : "u���"
		expected (nonprintable as hex) : "u"
		actual   (nonprintable as hex) : "u\xa0\x03\xe0\xbd\xdf\x7f"*/

	ft_printf("%c", 'e');
	/*      expected output : "e"
		your output     : "e���"
		expected (nonprintable as hex) : "e"
		actual   (nonprintable as hex) : "e\xa0\x03\xe0\xbd\xdf\x7f"*/

	char *str = NULL;

	ft_printf("%s!", str);
	/*    First line of code: {char *str = NULL; return test("%s!", str);
		SEGFAULT*/

	ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir");
	/*      expected output : "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir"
		your output     : "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoir"
		expected (nonprintable as hex) : "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdec\xc5\x93urc'\xc3\xa9taitunsoir"
		actual   (nonprintable as hex) : "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdec\xc5\x93urc'\xc3\xa9taitunsoir"*/

	ft_printf("%d", 42);
	/*      expected output : "42"
		your output     : "42�н�"
		expected (nonprintable as hex) : "42"
		actual   (nonprintable as hex) : "42\x90\x03\xd0\xbd\xdf\x7f"*/

	ft_printf("%d", 0);
	/*      expected output : "0"
		your output     : "0P��"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0P\x02\xf0\xbd\xdf\x7f"*/

	ft_printf("%d", INT_MAX);
	/*      expected output : "2147483647"
		your output     : "2147483647���3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647\xe0\x04\xe0\xbd\xdf\x7f3647"*/

	ft_printf("%d", INT_MIN - 1);
	/*      expected output : "2147483647"
		your output     : "2147483647��3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647\x10\x05\xe0\xbd\xdf\x7f3647"*/
	int r00 = 0;
	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);
	/*594 (moul_mix_1) : FAILED.
		First line of code: {int r00 = 0; return test("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);
		SIGABRT*/

	ft_printf("%i", 42);
	/*     expected output : "42"
		your output     : "42i"
		expected (nonprintable as hex) : "42"
		actual   (nonprintable as hex) : "42i"*/

	ft_printf("%i", -0);
	/*      expected output : "0"
		your output     : "0i"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0i"*/

	ft_printf("%i", 0);
	/*      expected output : "0"
		your output     : "0�н�"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0\xf0\x03\xd0\xbd\xdf\x7f"*/

	ft_printf("%i", INT_MAX);
	/*      expected output : "2147483647"
		your output     : "2147483647���3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647\xd0\x05\xe0\xbd\xdf\x7f3647"*/

	ft_printf("%i", INT_MIN);
	/*      expected output : "-2147483648"
		your output     : "-2147483648`/���83648"
		expected (nonprintable as hex) : "-2147483648"
		actual   (nonprintable as hex) : "-2147483648`/\xc0\xbd\xdf\x7f83648"*/

	ft_printf("%i", INT_MIN - 1);
	/*      expected output : "2147483647"
		your output     : "2147483647���3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647\xb0\x02\xf0\xbd\xdf\x7f3647"*/

	ft_printf("%i", INT_MAX + 1);
	/*      expected output : "-2147483648"
		your output     : "-2147483648��483648"
		expected (nonprintable as hex) : "-2147483648"
		actual   (nonprintable as hex) : "-2147483648\x06\xe0\xbd\xdf\x7f483648"*/

	ft_printf("%u", 42);
	/*      expected output : "42"
		your output     : "42`��"
		expected (nonprintable as hex) : "42"
		actual   (nonprintable as hex) : "42`\x06\xe0\xbd\xdf\x7f"*/

	ft_printf("Il fait au moins %u", -8000);
	/*      expected output : "Il fait au moins 4294959296"
		your output     : "Il fait au moins -8000"
		expected (nonprintable as hex) : "Il fait au moins 4294959296\x0a"
		actual   (nonprintable as hex) : "Il fait au moins -8000\x0a"*/

	ft_printf("%u", -0);
	/*      expected output : "0"
		your output     : "0���"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0\x90\x06\xe0\xbd\xdf\x7f"*/

	ft_printf("%u", 0);
	/*      expected output : "0"
		your output     : "0u"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0u"*/

	ft_printf("%u", INT_MAX);
	/*      expected output : "2147483647"
		your output     : "2147483647@���3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647@\x03\x90\xc0\xdf\x7f3647"*/

	ft_printf("%u", INT_MIN);
	/*      expected output : "2147483648"
		your output     : "-2147483648@���83648"
		expected (nonprintable as hex) : "2147483648"
		actual   (nonprintable as hex) : "-2147483648@\x03\x90\xc0\xdf\x7f83648"*/

	ft_printf("%u", INT_MIN - 1);
	/*     expected output : "2147483647"
		your output     : "2147483647���3647"
		expected (nonprintable as hex) : "2147483647"
		actual   (nonprintable as hex) : "2147483647\xc0\x06\xe0\xbd\xdf\x7f3647"*/

	ft_printf("%u", INT_MAX + 1);
	/*      expected output : "2147483648"
		your output     : "-2147483648���83648"
		expected (nonprintable as hex) : "2147483648"
		actual   (nonprintable as hex) : "-2147483648\xc0\x06\xe0\xbd\xdf\x7f83648"*/

	ft_printf("%x", 42);
	/*      expected output : "2a"
		your output     : "2a ��"
		expected (nonprintable as hex) : "2a"
		actual   (nonprintable as hex) : "2a \x07\xe0\xbd\xdf\x7f"*/

	ft_printf("%x", -0);
	/*      expected output : "0"
		your output     : "0 н�"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0 \x04\xd0\xbd\xdf\x7f"*/

	ft_printf("%x", 0);
	/*      expected output : "0"
		your output     : "0���"
		expected (nonprintable as hex) : "0"
		actual   (nonprintable as hex) : "0\xb0\x07\xe0\xbd\xdf\x7f"*/

	ft_printf("%x", INT_MAX);
	/*      expected output : "7fffffff"
		your output     : "7fffffff���ff"
		expected (nonprintable as hex) : "7fffffff"
		actual   (nonprintable as hex) : "7fffffff\xb0\x07\xe0\xbd\xdf\x7fff"*/

	ft_printf("%x", INT_MIN);
	/*      expected output : "80000000"
		your output     : "80000000���00"
		expected (nonprintable as hex) : "80000000"
		actual   (nonprintable as hex) : "80000000\xb0\x07\xe0\xbd\xdf\x7f00"*/

	ft_printf("%x", INT_MIN - 1);
	/*      expected output : "7fffffff"
		your output     : "7fffffffxffffff"
		expected (nonprintable as hex) : "7fffffff"
		actual   (nonprintable as hex) : "7fffffffxffffff"*/

	ft_printf("%x", INT_MAX + 1);
	/*      expected output : "80000000"
		your output     : "80000000@��00"
		expected (nonprintable as hex) : "80000000"
		actual   (nonprintable as hex) : "80000000@\x03\xf0\xbd\xdf\x7f00"*/
}
