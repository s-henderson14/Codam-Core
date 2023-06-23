/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:32:50 by shenders          #+#    #+#             */
/*   Updated: 2023/06/23 20:00:58 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	x_dir(int x_start, int x_end)
{
	if (x_start <= x_end)
		return (1);
	else
		return (-1);
}

int	y_dir(int y_start, int y_end)
{
	if (y_start <= y_end)
		return (1);
	else
		return (-1);
}
