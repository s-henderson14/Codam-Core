/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 07:19:10 by shenders      #+#    #+#                 */
/*   Updated: 2023/05/12 07:50:28 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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

void	load_coordinate(int *altitude, char *row)
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
		load_coordinate(map->altitude[i], row);
		free(row);
		i++;
	}
	map->altitude[i] = NULL;
}
