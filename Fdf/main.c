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
	int	width;
	int	height;
	int	**altitude;
	
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

void	place_coordinate(int *altitude, char *row)
{
	char	**coordinate;
	int	i;

	coordinate = ft_split(row, ' ');
	i = 0;
	while (coordinate[i])
	{
		altitude[i] = ft_atoi(coordinate[i]);
		free(coordinate[i]);
		i++;
	}
	free(coordinate);
}
void	parse_map(fdf *map, char *file)
{
	int	fd;
	int	i;
	char	*row;

	fd = open (file, O_RDONLY);
	map->height = map_height(file);
	map->width = map_width(file);
	map->altitude = (int**)malloc(sizeof(int*) * (map->height + 1));
	i= 0;
	while (i <= map->height)
		map->altitude[i++] =  (int*)malloc(sizeof(int) * (map->width + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{	
		row = get_next_line(fd);
		if (!row)
			break;
		place_coordinate(map->altitude[i], row);
		free(row);
		i++;
	}
	map->altitude[i] = NULL;
}

int	main(int argc, char **argv)
{	
	fdf	*map;
	int	i;
	int	j;
	
	(void)argc;
	map = (fdf*)malloc(sizeof(fdf));
	i = 0;
	parse_map(map, argv[1]);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d  ", map->altitude[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

	
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
