#include "../../fdf.h"

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	/*if (!map->mlx)
		clean_error(map, map->points);*/
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		clean_error(map, map->points);
	render_map(map); // <--------------------------------------DONT'T FORGET
	if (mlx_image_to_window(map->mlx,map->img, 0, 0) == -1)
		mlx_map_error(map);
	mlx_loop_hook(map->mlx, &esc_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}	