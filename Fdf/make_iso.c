#include "../../fdf.h"

void make_iso(int *x , int *y, int z)
{
	double	angle;
	int		temp;

	angle = 0.6;
	temp = *x;
	
	*x = (int)(temp - *y) * cos(angle);
	*y = (int)(temp + *y) * sin(angle) - z;
}