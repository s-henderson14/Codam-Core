/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 12:54:32 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/19 12:07:26 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;

	(void)argc;
	map = (t_map*)malloc(sizeof(t_map));
	parse_map(map, argv[1]);
	map->mlx = mlx_init(1000, 1000, "Fdf", false);
	map->img = mlx_new_image(map->mlx, 1000, 1000);
	//draw_line(10, 10, 600, 300, map);
	map->scale = 20;
	render_map(map);
	mlx_image_to_window(map->mlx,map->img, 0, 0);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (0);
}
	/*while ( i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d  ", map->points[i][j]);
			j++;
		}
		i++;

	}
}*/
