#include <unistd.h>
#include <stdio.h>

int    print_char(int c)
{
        write(1, &c, 1);
		return (1);
}
