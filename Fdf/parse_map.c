/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:58:19 by shenders          #+#    #+#             */
/*   Updated: 2023/06/22 17:22:44 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	find_height(char *map)
{
	int		fd;
	int		height;
	char	*row;

	fd = open(map, O_RDONLY);
	height = 0;
	row = get_next_line(fd);
	if (!row)
		return (-1);
	while (row != NULL)
	{
		height++;
		free(row);
		row = get_next_line(fd);
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
	row = get_next_line(fd);
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


