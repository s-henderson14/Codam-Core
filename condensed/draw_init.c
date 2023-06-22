/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:34:55 by shenders          #+#    #+#             */
/*   Updated: 2023/06/22 20:18:29 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_draw	*draw_init(int x0, int y0, int x1, int y1)
{
	t_draw	draw;
	
	draw.x0 = x0;
	draw.y0 = y0;
	draw.x1 = x1;
	draw.y1 = y1;
	draw.x_diff = ft_abs(x1 - x0);
	draw.y_diff = ft_abs(y1 - y0);
	draw.error = draw.x_diff - draw.y_diff;
	return (&draw);
}

