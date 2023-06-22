#include "../../fdf.h"

void	draw_line(t_map *map, t_draw *draw)
{
	int	e2;
	
	while (draw->x0 != draw->x1 || draw->y0 != draw->y1)
	{
		if (draw->x0 <= (int )map->img->width && draw->x0 > 0 \
		&& draw->y0 <= (int )map->img->height && draw->y0 > 0)
			mlx_put_pixel(map->img, draw->x0, draw->y0, map->colour);
		e2 = draw->error * 2;
		if (e2 > -draw->y_diff)
		{
			draw->error -= draw->y_diff;
			draw->x0 += x_dir(draw->x0, draw->x1);
		}
		if (e2 < draw->x_diff)
		{
			draw->error += draw->x_diff;
			draw->y0 += y_dir(draw->y0, draw->y1);
		}
		if (draw->x0 == draw->x1 && draw->y0 == y1)
		{
			if (draw->x0 < (int )map->img->width && draw->x0 > 0 && draw->y0 < (int )map->img->height && draw->y0 > 0)
				mlx_put_pixel(map->img, draw->x0, draw->y0, map->colour);
			break ;
		}
	}
}
