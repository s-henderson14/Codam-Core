/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 18:55:04 by shenders      #+#    #+#                 */
/*   Updated: 2023/04/20 18:46:29 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct
{	
	int	x_pos;
	int	y_pos;
	int	**height;
	
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

char	**parse_map(int fd)
{
	char	*line;
	char	*map;
	char	**full_map;

	map = NULL;
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin(map, line);
		if (!map)
			exit(0);
	}
	full_map = ft_split(map, '\n');
	return (full_map);
}	

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1000, 1000, "Hello, World!", false);
	img = mlx_new_image(mlx, 1000, 1000);
	while (map)
	{	

	while (x != 500)
		mlx_put_pixel(img, x++, 250, 0xFFFFFF);
	while (y != 500)
		mlx_put_pixel(img, 250, y++, 0xFFFFFF);
	mlx_image_to_window(mlx , img, 250, 250);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
