/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:54:32 by shenders          #+#    #+#             */
/*   Updated: 2023/06/25 18:31:01 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{	
	t_map	*map;
	int		fd;

	if (argc != 2)
		error();
	fd = file_check(argv[1]);
	if (!fd)
		error();
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error();
	parse_map(map, argv[1]);
	mlx_start(map);
	clear_array(map, map->points);
	free(map);
	close(fd);
	return (0);
}
