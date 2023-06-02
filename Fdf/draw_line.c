/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:50:46 by shenders          #+#    #+#             */
/*   Updated: 2023/06/02 17:09:47 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    draw_line(int x0, int y0, int x1, int y1, t_map *map)
{   
    int error;
    int e2;
    int x_diff;
    int y_diff;
    int z0;
    int z1;

    z0 = map->points[(int)y0][(int)x0];
    z1 = map->points[(int)y1][(int)x1];

	/*make_iso(&x0, &y0, z0);
    make_iso(&x1, &y1, z1);*/

    x0 -= map->width / 2;
    y0 -= map->height / 2;
    x1 -= map->width / 2;
    y1 -= map->height / 2;
    
    map->scale = 1 * ((HEIGHT / 2) / map->height);
    x0 *= map->scale;
    x1 *= map->scale;
    y0 *= map->scale;
    y1 *= map->scale;
    z0 *= map->scale;
    z1 *= map->scale;
    
    make_iso(&x0, &y0, z0);
    make_iso(&x1, &y1, z1);
    
    if (z0 || z1 > 0)
        map->colour = 0x4C82E6; // Red color for higher elevation
    else
        map->colour = 0xFFFFFF; // White color for lower elevation

    x0 += WIDTH / 2;
    y0 += HEIGHT / 2;
    x1 += WIDTH / 2;
    y1 += HEIGHT / 2;

    x_diff = abs(x1 - x0);
    y_diff = abs(y1 - y0);
    error = x_diff - y_diff;
    while (x0 != x1 || y0 != y1)
    {   
        if (x0 < (int)map->img->width && x0 > 0 && y0 < (int)map->img->height && y0 > 0)
            mlx_put_pixel(map->img, x0, y0, map->colour);
        e2 = error * 2;
        if (e2 > -y_diff)
        {   
            error -= y_diff;
            x0 += x_dir(x0, x1);
        }
        if (e2 < x_diff)
        {
            error += x_diff;
            y0 += y_dir(y0, y1);
        }
        if (x0 == x1 && y0 == y1)
        {
            if (x0 < (int)map->img->width && x0 > 0 && y0 < (int)map->img->height && y0 > 0)
                mlx_put_pixel(map->img, x0, y0, map->colour);
            break;
        }
    }
}