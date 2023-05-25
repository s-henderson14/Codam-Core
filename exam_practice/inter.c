#include <unistd.h>

/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.*/

int	is_duplicate(char *str, char c, int index)
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

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j] && !(is_duplicate(argv[1], argv[2][j], i)))
			{
				write(1, &argv[1][i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}


/* Test Cases

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
