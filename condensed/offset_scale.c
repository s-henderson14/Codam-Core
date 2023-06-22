/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:49:15 by shenders          #+#    #+#             */
/*   Updated: 2023/06/22 20:19:03 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	offset_and_scale(t_map *map, t_draw *draw)
{
	draw->x0 -= map->width / 2;
	draw->y0 -= map->height / 2;
	draw->x1 -= map->width / 2;
	draw->y1 -= map->height / 2;
	map->scale = (float )(HEIGHT / 4) / map->height;
	draw->x0 *= map->scale;
	draw->y0 *= map->scale;
	draw->x1 *= map->scale;
	draw->y1 *= map->scale;
}
