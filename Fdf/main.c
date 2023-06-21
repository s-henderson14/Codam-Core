/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:54:32 by shenders          #+#    #+#             */
/*   Updated: 2023/06/19 23:33:26 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		error();
	fd = file_check(argv[1]);
	if (!fd)
		error();		
	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		error();
	parse_map(map, argv[1]);
	mlx_start(map);
	close(fd);
	return (0);
}

