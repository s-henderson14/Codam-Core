/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:58:19 by shenders          #+#    #+#             */
/*   Updated: 2023/06/02 07:43:36 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	find_height(char *map)
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

int	find_width(char *map)
{
	int		fd;
	int		width;
	int		i;
	char	*line;
	char	**args;

	fd = open (map, O_RDONLY);
	width = 0;
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	args = ft_split(line, ' ');
	while (args[i] && *args[i] != 10)
	{
		width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

void	save_point(int *point, char *row)
{
	char	**coordinate;
	int		i;
	
	coordinate = ft_split(row, ' ');
	i = 0;
	while (coordinate[i])
	{
		point[i] = ft_atoi(coordinate[i]);
		free(coordinate[i]);
		i++;
	}
	free(coordinate);
}


void parse_map(t_map *map, char *file)
{	
	int		fd;
	char	*row;
	int		i;

	map->height = find_height(file);
	map->width = find_width(file);
	map->points = (int **)malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while (i <= map->height)
		map->points[i++] = (int*)malloc(sizeof(int) * (map->width));
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{	
		row = get_next_line(fd);
		if (!row)
			break;
		save_point(map->points[i], row);
		free(row);
		i++;
	}
	close(fd);
	map->points[i] = NULL;
}

