/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:58:19 by shenders          #+#    #+#             */
/*   Updated: 2023/06/23 20:01:59 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_height(char *map)
{
	int		fd;
	int		height;
	char	*row;

	fd = open(map, O_RDONLY);
	height = 0;
	row = get_next_line(fd, 0);
	if (!row)
		return (-1);
	while (row != NULL)
	{
		height++;
		free(row);
		row = get_next_line(fd, 0);
	}
	close(fd);
	return (height);
}

int	find_width(char *map)
{
	int		fd;
	int		width;
	int		i;
	char	*row;
	char	**args;

	fd = open (map, O_RDONLY);
	width = 0;
	i = 0;
	row = get_next_line(fd, 1);
	if (!row)
		return (-1);
	args = ft_split(row, ' ');
	if (!args)
		return (free(row), -1);
	while (args[i] && *args[i] != 10)
	{
		width++;
		i++;
	}
	free(row);
	clean_split(args);
	close(fd);
	return (width);
}



void	save_point(t_map *map, int *point, char *row)
{
	char	**coordinate;
	int		i;

	coordinate = ft_split(row, ' ');
	if (!coordinate)
		clean_error(map, map->points);
	i = 0;
	while (coordinate[i])
	{
		point[i] = ft_atoi(coordinate[i]);
		free(coordinate[i]);
		i++;
	}
	free(coordinate);
}

void	add_points(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (!fd)
		clean_error(map, map->points);
	i = 0;
	line = get_next_line(fd, 0);
	if (!line)
	{	
		close(fd);
		clean_error(map, map->points);
	}
	while (line)
	{
		save_point(map, map->points[i++], line);
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
}

void	parse_map(t_map *map, char *file)
{
	char	*row;
	int		i;

	row = malloc(sizeof(char));
	map->height = find_height(file);
	map->width = find_width(file);
	map->points = (int **) ft_calloc((map->height), sizeof (int *));
	if (map->height == -1 || map->width == -1 || !map->points)
		clean_error(map, map->points);
	i = 0;
	while (i < map->height)
	{
		map->points[i++] = (int *)ft_calloc((map->width), sizeof(int));
		if (!map->points[0])
			clean_error(map, map->points);
	}
	add_points(map, file);
}
