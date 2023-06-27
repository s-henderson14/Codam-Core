/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:09:26 by shenders          #+#    #+#             */
/*   Updated: 2023/06/27 18:32:05 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	render_map(map);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) == -1)
		mlx_map_error(map);
	mlx_loop_hook(map->mlx, &esc_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}
