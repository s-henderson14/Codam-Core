/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 07:50:46 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/12 12:00:32 by shenders      ########   odam.nl         */
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

void	draw_line(int x_start, int y_start, int x_end, int y_end, fdf *map)
{
	int	diff_x;
	int	diff_y;
	int	err;
	int	err2;

	diff_x = x_end - x_start;
	diff_y = y_end - y_start;
	err = (diff_x) - (diff_y);
	while (x_start != x_end || y_start != y_end)
	{
		err2 = err * 2;
		if (err2 > diff_y)
		{	
			err -= (diff_y);
			x_start += x_dir(x_start, x_end);
		}
		if (err2 < diff_x)
		{
			err += diff_x;
			y_start += y_dir(y_start, y_end);
		}
		mlx_put_pixel(map->img_ptr, x_start, y_start, 0xFFFFFF);
	}
}




