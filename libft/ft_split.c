#include <stdio.h>
#include "libft.h"

char	**ft_split(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	//create temp char pointer "temp"
	//create char pointer "str"
	//create int index "i"
	//iterate through s
	//if char in 's' is equal to char 'c'
	//make c equal to a '\0'
	//take index of when 's' == 'c'
	//use index to malloc correct size - sizeof(char) * (len + 1)
	//protect malloc
	//make "temp" == "str"
	//free "str"
	//how to loop round >> malloc >> add malloc str to temp and create enough buffer size for it
	char	**temp;
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = (char *)s;
	temp = (char **)str;
	while (str[i])
	{	
		if ( str[i] == c)
		{       
			temp[j] = ft_substr(str, 0, i);
			if (str)
				free(str);
			j++;
			i++;
		}
		i++;	
	}
	if (temp)
		return (temp);
	return (char **) str;	

}

/*int	main()
{
	char	string[] = "Sean was not yet sure how the function worked";
	char	delimta = " ";

	printf("%p", ft_split(string, delimta);
}*/
