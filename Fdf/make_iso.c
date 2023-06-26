/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:17:16 by sean              #+#    #+#             */
/*   Updated: 2023/06/26 22:28:09 by sean             ###   ########.fr       */
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