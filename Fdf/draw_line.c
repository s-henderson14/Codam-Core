/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:50:46 by shenders          #+#    #+#             */
/*   Updated: 2023/06/27 10:58:08 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

void    draw_line(t_point *p0, t_point *p1, t_map *map)
{   
    int e2;
    t_draw  draw;
    
    draw = draw_init(p0, p1);
    scale_and_offset(&draw, map);
    while (draw.x0 != draw.x1 || draw.y0 != draw.y1)
    {    
        if (draw.x0 <= (int)map->img->width && draw.x0 > 0 && draw.y0 <= (int)map->img->height && draw.y0 > 0)
            mlx_put_pixel(map->img, draw.x0, draw.y0, map->colour);
        e2 = draw.error * 2;
        if (e2 > -draw.y_diff)
        {   
            draw.error -= draw.y_diff;
            draw.x0 += x_dir(draw.x0, draw.x1);
        }
        if (e2 < draw.x_diff)
        {
            draw.error += draw.x_diff;
            draw.y0 += y_dir(draw.y0, draw.y1);
        }
        if (draw.x0 == draw.x1 && draw.y0 == draw.y1)
        {
            if (draw.x0 < (int)map->img->width && draw.x0 > 0 && draw.y0 < (int)map->img->height && draw.y0 > 0)
                mlx_put_pixel(map->img, draw.x0, draw.y0, map->colour);
            break;
        }
    }
}
    // draw.x0 -= map->width / 2;
    // draw.y0 -= map->height / 2;
    // draw.x1 -= map->width / 2;
    // draw.y1 -= map->height / 2; 
    // map->scale = (float)(HEIGHT / 2) / map->height;
    // draw.x0 *= map->scale;
    // draw.y0 *= map->scale;
    // draw.x1 *= map->scale;
    // draw.y1 *= map->scale;
    // make_iso(&draw.x0, &draw.y0, draw.z0);
    // make_iso(&draw.x1, &draw.y1, draw.z1);
    
    // if (draw.z0 || draw.z1 > 0)
    //     map->colour = 0xdb4d69;
    // else
    //     map->colour = 0xFFFFFF;
        
    // draw.x0 += WIDTH / 2;
    // draw.y0 += HEIGHT / 2;
    // draw.x1 += WIDTH / 2;
    // draw.y1 += HEIGHT / 2;
    // draw.x_diff = ft_abs(draw.x1 - draw.x0);
    // draw.y_diff = ft_abs(draw.y1 - draw.y0);
    // draw.error = draw.x_diff - draw.y_diff;