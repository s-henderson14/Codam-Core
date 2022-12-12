#include <stdio.h>
#include "get_next_line_utils.c"
#include <string.h>

char	*linecut(char *line, int c)
{
	int		i;
	int		j;
	char	*line_end;

	i = 0;
	j = 0;
	line_end = NULL;
	while (line[i])
	{
		if (line[i] == c)
		{	
			i++;
			if (line[i] == '\0') // if we find a null terminator directly after the '\n' then we haven't anything extra to cut from our line. 
				return(0);
			else if (line[i] != '\0')
				line_end = ft_substr(line, i, strlen(line) - i);	
			return (line_end);
		}
		i++;
	}
	if (line[i] == '\0' && c =='\0')
		return (ft_substr(line, 0, strlen(line)));		
	return (strdup(""));
}

int	main()
{
	char	*string;

	string = "Wagwan padawan dont gimme that newline\n and nothing thereafter";
	printf("%s", linecut(string, '\n'));
}