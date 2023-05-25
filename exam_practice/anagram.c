#include <stdio.h>

int	int_occurence(char *str1, char *str2)
{
	int	i;
	int	count1;
	int	count2;
	char	letter1;
	
	i = 0;
	count1 = 0;
	count2 = 0;
	letter1 = str1[i];
	while (str1[i])
	{
		if (str1[i] == letter1)
			count1++;
		i++;
	}
	i = 0;
	while (str2[i])
	{	
		if (str2[i] == letter1)
			count2++;
		i++;
	}
	if (count1 - count2 == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (0);
	while (argv[i])
	{
		if (int_occurence(argv[1], argv[2]))
			i++;
		else
		{	
			printf("STRING 1 IS NOT AN ANAGRAM OF STRING 2\n");
			return (0);
		}
	}
	printf("STRING 1 IS AN ANAGRAM OF  STRING 2\n");
	return (0);
}












		
