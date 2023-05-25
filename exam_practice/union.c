#include <unistd.h>

/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.*/

int	written_before(char *str, char c, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= index)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	in_string_1(char *str1, char c)
{	
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char ** argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 3)
	{	
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (!(written_before(argv[1], argv[1][i], i)))
			write(1, &argv[1][i], 1);
		i++;
	}
	while (argv[2][j])
	{	
		if (!(in_string_1(argv[1], argv[2][j])) && !(written_before(argv[2], argv[2][j], j)))
			write(1, &argv[2][j], 1);
		j++;

	}
	write(1, "\n", 1);
	return (0);
}

/*$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
