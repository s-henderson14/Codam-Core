/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:30:59 by shenders          #+#    #+#             */
/*   Updated: 2023/06/23 20:01:25 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	clean_error(t_map *map, int **arr)
{
	if (arr)
		clear_array(map, arr);
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	mlx_map_error(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	clear_array(map, map->points);
	free(map);
	exit(EXIT_FAILURE);
}
