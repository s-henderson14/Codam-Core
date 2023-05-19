/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 07:50:46 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/19 12:39:12 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	x_dir(int x_start, int x_end)
{
	int	x_dir;

	if (x_start < x_end)
		x_dir = 1;
	else 
		x_dir = -1;
	return (x_dir);
}

int	y_dir(int y_start, int y_end)
{
	int	y_dir;

	if (y_start < y_end)
		y_dir = 1;
	else
		y_dir = -1;
	return (y_dir);
}

void make_isometric(int *x , int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	draw_line(int x0, int y0, int x1, int y1, t_map *map)
{	
	int	error;
	int	e2;
	int	x_diff;
	int	y_diff;
	int	z0;
	int	z1;
	
	x0 *= map->scale;
	x1 *= map->scale;
	y0 *= map->scale;
	y1 *= map->scale;
	z0 = map->points[(int)y0][(int)x0];
	z1 = map->points[(int)y1][(int)x1];
	make_isometric(&x0, &y0, z0);
	make_isometric(&x1,&y1, z1);

	x0 += 150;
	y0 += 150;
	x1 += 150;
	y1 += 150;

	x_diff = x1 - x0;
	y_diff = y1 - y0;
	error = x_diff - y_diff;
	while (x0 != x1 || y0 != y1)
	{	
		mlx_put_pixel(map->img, x0, y0, 0XFFFFFF);
		e2 = error * 2;
		if (e2 >= -y_diff)
		{	
			error -= y_diff;
			x0 += x_dir(x0, x1);
		}
		if (e2 <= x_diff)
		{
			error += x_diff;
			y0 += y_dir(y0, y1);
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
	
