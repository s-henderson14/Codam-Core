/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:17:24 by sean              #+#    #+#             */
/*   Updated: 2023/06/20 20:21:02 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../fdf.h"

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	//map->scale = 4;
	render_map(map);
	mlx_image_to_window(map->mlx,map->img, 0, 0);
	mlx_loop_hook(map->mlx, &esc_key_hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}	