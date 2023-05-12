/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 18:55:04 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/12 15:23:26 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MLX42/MLX42.h"
#include "../../fdf.h"
#include "../../libft/libft.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	fdf			*map;	

	(void)argc;
	map = (fdf*)malloc(sizeof(fdf));
	parse_map(map, argv[1]);
	map->mlx_ptr = mlx_init(1000, 1000, "Fdf", false);
	map->img_ptr = mlx_new_image(map->mlx_ptr, 1000, 1000);
	draw_line(1, 1, 4, 4, map);
	mlx_loop(map->mlx_ptr);
	mlx_terminate(map->mlx_ptr);
	return (0);
}

/*int	main(int argc, char **argv)
{

	mlx = mlx_init(1000, 1000, "Hello, World!", false);
	img = mlx_new_image(mlx, 1000, 1000);
	while (x != 500)
		mlx_put_pixel(img, x++, 250, 0xFFFFFF);
	while (y != 500)
		mlx_put_pixel(img, 250, y++, 0xFFFFFF);
	mlx_image_to_window(mlx , img, 250, 250);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}*/

/*int	main()
{
	fdf			*map;
	
	map = NULL;
	map->mlx_ptr = mlx_init(1000, 1000, "Fdf", false);
	map->img_ptr = mlx_new_image(map->mlx_ptr, 1000, 1000);
	draw_line (1, 1, 4, 4, map);
	mlx_loop(map->mlx_ptr);
	mlx_terminate(map->mlx_ptr);
	return (0);
}*/
