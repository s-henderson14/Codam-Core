/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 07:50:46 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/27 10:50:03 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <math.h>

int	x_dir(int x_start, int x_end)
{

	if (x_start <= x_end)
		return (1);
	else 
		return (-1);
}

int	y_dir(int y_start, int y_end)
{
	if (y_start <= y_end)
		return (1);
	else
		return (-1);
}

void make_isometric(int *x , int *y, int z)
{
	double	angle;
	int		temp;

	angle = 0.8;
	temp = *x;
	
	*x = (int)(temp - *y) * cos(angle);
	*y = (int)(temp + *y) * sin(angle) - z;
}

void	draw_line(int x0, int y0, int x1, int y1, t_map *map)
{	
	int	error;
	int	e2;
	int	x_diff;
	int	y_diff;
	int	z0;
	int	z1;

	z0 = map->points[(int)y0][(int)x0];
	z1 = map->points[(int)y1][(int)x1];

	x0 *= map->scale;
	x1 *= map->scale;
	y0 *= map->scale;
	y1 *= map->scale;
	//z0 *= map->scale;
	//z1 *= map->scale;
	

    if (z0 || z1 > 0)
        map->colour = 0x4C82E6; // Red color for higher elevation
	else
        map->colour = 0xFFFFFF; // White color for lower elevation

	make_isometric(&x0, &y0, z0);
	make_isometric(&x1, &y1, z1);

	x0 += 150;
	y0 += 150;
	x1 += 150;
	y1 += 150;

	x_diff = abs(x1 - x0);
	y_diff = abs(y1 - y0);
	error = x_diff - y_diff;
	while (x0 != x1 || y0 != y1)
	{	
		mlx_put_pixel(map->img, x0, y0, map->colour);
		e2 = error * 2;
		if (e2 > -y_diff)
		{	
			error -= y_diff;
			x0 += x_dir(x0, x1);
		}
		if (e2 < x_diff)
		{
			error += x_diff;
			y0 += y_dir(y0, y1);
		}
		if (x0 == x1 && y0 == y1)
		{	
			mlx_put_pixel(map->img, x0, y0, map->colour);
			break;
		}
	}
}

/*t_draw	get_line_info(t_map *map)
{
	t_draw	draw;

	draw.x_diff = x - start_point->x;
	draw.y_diff = end_point->y - start_point->y;
	draw.error = draw.x_diff - draw.y_diff;
	draw.x_cor = start_point->x;
	draw.y_cor = start_point->y;
	draw.x_dir = x_dir(start_point->x, end_point->x);
	draw.y_dir = y_dir(start_point->y, end_point->y);
	return (draw);
}*/
	
