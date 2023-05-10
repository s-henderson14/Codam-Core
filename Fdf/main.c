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
#include "../../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct
{	
	int	x_pos;
	int	y_pos;
	int	**height;
	
	void	*mlx_ptr;
	void	*win_ptr;
}		fdf;

int	map_height(char *map)
{	
	int	fd;
	int	height;
	
	fd = open(map, O_RDONLY);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	map_width(char *map)
{
	int	fd;
	int	width;
	int	i;
	char	*line;
	char	**args;

	fd = open (map, O_RDONLY);
	width = 0;
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	args = ft_split(line, ' ');
	while (args[i])
	{	
		width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

/*char	**parse_map(fdf *data, char *map)
{
	int	fd;

	fd = open (map, O_RDONLY);
	data->y_pos = map_height(map);
	data->x_pos = map_width(map);
}*/

int	main(void)
{	
	printf("MAP_HEIGHT = %d\nMAP_WIDTH = %d\n", map_height("42.fdf"), map_width("42.fdf"));

	/*	fdf	*data;
	int	fd;
	
	data = (fdf*)malloc(sizeof(fdf));
	fd = open("42.fdf", O_RDONLY);
*/
	
/*	mlx_t		*mlx;
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
	*/
	return (0);
}
