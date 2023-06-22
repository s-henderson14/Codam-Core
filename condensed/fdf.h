/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:22:18 by shenders          #+#    #+#             */
/*   Updated: 2023/06/22 20:17:33 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define WIDTH 2500
# define HEIGHT 1440

typedef struct s_map
{
	int			width;
	int			height;
	int			**points;
	float		scale;
	int			colour;
	int			x_offset;
	int			y_offset;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_map;

typedef struct s_draw
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	error;
	int	x_diff;
	int	y_diff;
}		t_draw;	

int		find_height(char *map);

int		find_width(char *map);

int		x_dir(int x_start, int x_end);

int		y_dir(int y_start, int y_end);

int		ft_abs(int x);

int		file_check(char *filename);

void	mlx_start(t_map *map);

void	parse_map(t_map *map, char *file);

void	save_point(t_map *map, int *point, char *row);

void	draw_line(t_map *map, t_draw *line);

void	make_iso(int *x, int *y, int z);

void	render_map(t_map *map);

void	error(void);

void	esc_key_hook(void *param);

t_draw	*draw_init(int x0, int y0, int x1, int y1);

void	clean_split(char **arr);

void	clear_array(t_map *map, int **points);

void	clear_array1(int **points);

void	clean_error(t_map *map, int **arr);

void	mlx_map_error(t_map *map);

void	add_points(t_map *map, char *file);

void	colour(t_map *map, int	z0, int z1);

void	scaler(t_map *map, t_draw *line);



#endif
