#include <stdio.h>
#include "get_next_line_utils.c"

char	*find_new_line(char *txt, int c)
{
	int	i;

	i = 0;
	//if (!txt[i])
		//return (NULL);
	while (txt[i])
	{	
		if (txt[i] == (char)c)
			return (ft_substr(txt, 0, i + 1));
		i++;
	}	
	return (0);			
}

int	main()
{
	char	*string;
	char	*nonstring;

	string = "I was walking by the side of the road looking for a backslash n, they look sort of like this.\n An then just like magic I saw one.";
	nonstring = "";
	printf("%d\n", printf("%s\n", find_new_line(string, 'l')));
	//printf("%s", find_new_line(string,'z'));
	//printf("%s", find_new_line(nonstring, 'p'));
}