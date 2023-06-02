#include "../../fdf.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}