#include "../../fdf.h"

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	render_map(map);
	mlx_image_to_window(map->mlx,map->img, 0, 0);
	mlx_loop_hook(map->mlx, &esc_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}	