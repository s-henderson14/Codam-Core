#include <unistd.h>
#include <stdio.h>

int    print_char(int c)
{
        write(1, &c, 1);
	if (c)
		return (1);
	return (0);
}

int	main()
{
	printf("%d\n", print_char('y'));
}
