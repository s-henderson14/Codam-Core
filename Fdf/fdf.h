#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct
{
	int	width;
	int	height;
	int	**points;
	int	scale;
	int	colour;


	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_map;

typedef struct
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	error;
	int	error2;
	int	x_diff;
	int	y_diff;
}		t_draw;
	

int		map_height(char *map);

int		map_width(char *map);

int		x_dir(int x_start, int x_end);

int		y_dir(int y_start, int y_end);

void	parse_map(t_map *map, char *file);

void	save_point(int *point, char *row);

void	draw_line(int x0, int y0, int x1, int y1, t_map *map);

void	render_map(t_map *map);

#endif
