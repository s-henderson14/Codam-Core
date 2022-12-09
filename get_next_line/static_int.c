#include <stdio.h>

int	count()
{
	static int	counter;

	counter++;
	return (counter);
}
int	main()
{	
	int	i;

	i = 0;
	while (i < 10)
	{	
		printf("%d", count());
		i++;
	}
	return (0);
}