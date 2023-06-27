/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:31:07 by shenders          #+#    #+#             */
/*   Updated: 2023/06/25 18:29:42 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	clean_error(t_map *map, int **arr)
{
	if (arr)
		clear_array(map, arr);
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	clear_array(t_map *map, int **points)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (points != NULL)
			free(points[y]);
		y++;
	}
	free(points);
}

void	mlx_map_error(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	clear_array(map, map->points);
	free(map);
	exit(EXIT_FAILURE);
}

void	clean_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}






// void	clear_array1(int **points)
// {
// 	int	i;

// 	i = 0;
// 	while (points[i])
// 	{
// 		if (points != NULL)
// 			free(points[i]);
// 		i++;
// 	}
// 	exit(EXIT_FAILURE);
// }