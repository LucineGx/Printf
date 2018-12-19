// WILDCHARS
// COLOR
// flag L
// FILE DESCRIPORS

#include "srcs/printf.h"
#include <string.h>

void		test_it(char *result, char *ft_result, int ret, int ft_ret, int n)
{
	if (strcmp(result, ft_result) != 0 || ret != ft_ret)
	{
		if (strcmp(result, ft_result) != 0)
			printf("%serror STRING %d %s\nyour: |%s|\norig: |%s|\n\n ", RED, n, RESET, ft_result, result);
		if (ret != ft_ret)
			printf("%serror RETURN %d %s\nyour: |%d|\norig: |%d|\n\n ", MAGENTA, n, RESET, ft_ret, ret);
	}
	else
		printf("%sOK %d ! %s\n", CYAN, n, RESET);
}

int			main()
{
	char	c = 'k';
	char	c_null = '\0';
	int		n = 42;
	char	*s = "a man's dream would never die !";
	char	*s_null = NULL;
	char	*s_empty = "";

	char *result;
	char **ft_result;
	ft_result = malloc(sizeof(char*));

	int ret;
	int ft_ret;

// tests conv c 1

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%c", c);
	ft_ret = ft_printf(ft_result, "%c", c);

	test_it(result, *ft_result, ret, ft_ret, 1);
	free(result);


	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%c", c_null);
	ft_ret = ft_printf(ft_result, "%c", c_null);

	test_it(result, *ft_result, ret, ft_ret, 1);
	free(result);


	ft_ret = ft_printf(ft_result, "%c", s);

	// flag h 2

	ft_ret = ft_printf(ft_result, "%hc", c);

	// flag hh 3

	ft_ret = ft_printf(ft_result, "%hhc", c);

	// flag l 4				!! WILDCHAR SI UTILISE AVEC c

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%lc", c);
	ft_ret = ft_printf(ft_result, "%lc", c);

	test_it(result, *ft_result, ret, ft_ret, 4);
	free(result);

	// flag ll 5

	ft_ret = ft_printf(ft_result, "%llc", c);

	// flag L 6

	ft_ret = ft_printf(ft_result, "%Lc", c);

	// flag # 7

	ft_ret = ft_printf(ft_result, "%#c", c);

	// flag 0 8

	ft_ret = ft_printf(ft_result, "%0c", c);

	// flag - 9

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%-c", c);
	ft_ret = ft_printf(ft_result, "%-c", c);

	test_it(result, *ft_result, ret, ft_ret, 9);
	free(result);

	// flag + 10

	ft_ret = ft_printf(ft_result, "%+c", c);

	// flag ' ' 11

	ft_ret = ft_printf(ft_result, "% c", c);

	// fw 12

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%12c", c);
	ft_ret = ft_printf(ft_result, "%12c", c);

	test_it(result, *ft_result, ret, ft_ret, 12);
	free(result);

	// prec 13

	ft_ret = ft_printf(ft_result, "%.13c", c);

	// couleurs 14
	// fd 15


	// tests conv s1 16

	result = malloc(sizeof(char) * 30);

	ret = sprintf(result, "%s", s);
	ft_ret = ft_printf(ft_result, "%s", s);

	test_it(result, *ft_result, ret, ft_ret, 16);
	free(result);


	result = malloc(sizeof(char) * 30);

	ret = sprintf(result, "%s", s_null);
	ft_ret = ft_printf(ft_result, "%s", s_null);

	test_it(result, *ft_result, ret, ft_ret, 16);
	free(result);


	result = malloc(sizeof(char) * 30);

	ret = sprintf(result, "%s", s_empty);
	ft_ret = ft_printf(ft_result, "%s", s_empty);

	test_it(result, *ft_result, ret, ft_ret, 16);
	free(result);


	ft_ret = ft_printf(ft_result, "%s", c);


	ft_ret = ft_printf(ft_result, "%s", n);


	// flag h 2

	ft_ret = ft_printf(ft_result, "%hc", c);

	// flag hh 3

	ft_ret = ft_printf(ft_result, "%hhc", c);

	// flag l 4				!! WILDCHAR SI UTILISE AVEC c

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%lc", c);
	ft_ret = ft_printf(ft_result, "%lc", c);

	test_it(result, *ft_result, ret, ft_ret, 4);
	free(result);

	// flag ll 5

	ft_ret = ft_printf(ft_result, "%llc", c);

	// flag L 6

	ft_ret = ft_printf(ft_result, "%Lc", c);

	// flag # 7

	ft_ret = ft_printf(ft_result, "%#c", c);

	// flag 0 8

	ft_ret = ft_printf(ft_result, "%0c", c);

	// flag - 9

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%-c", c);
	ft_ret = ft_printf(ft_result, "%-c", c);

	test_it(result, *ft_result, ret, ft_ret, 9);
	free(result);

	// flag + 10

	ft_ret = ft_printf(ft_result, "%+c", c);

	// flag ' ' 11

	ft_ret = ft_printf(ft_result, "% c", c);

	// fw 12

	result = malloc(sizeof(char) * 25);

	ret = sprintf(result, "%12c", c);
	ft_ret = ft_printf(ft_result, "%12c", c);

	test_it(result, *ft_result, ret, ft_ret, 12);
	free(result);

	// prec 13

	ft_ret = ft_printf(ft_result, "%.13c", c);

	// couleurs 14
	// fd 15

	// tests conv p
	// tests conv d
	// tests conv i
	// tests conv o
	// tests conv u
	// tests conv x
	// tests conv X
	// tests conv f
	// tests conv e
	// tests conv g
	// tests conv b
	// tests conv r
	// tests conv k

	return 0;
}
