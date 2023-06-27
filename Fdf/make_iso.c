/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:03:55 by shenders          #+#    #+#             */
/*   Updated: 2023/06/23 20:01:51 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	make_iso(int *x, int *y, int z)
{
	double	angle;
	int		temp;

	angle = 0.65;
	temp = *x;
	*x = (int )(temp - *y) *cos(angle);
	*y = (int )(temp + *y) *sin(angle) - z;
}
