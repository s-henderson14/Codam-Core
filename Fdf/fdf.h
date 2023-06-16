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

typedef struct
{
	int	width;
	int	height;
	int	**points;
	float	scale;
	int	colour;
	int	x_offset;
	int	y_offset;


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

void	save_point(int *point, char *row);

void	draw_line(int x0, int y0, int x1, int y1, t_map *map);

void 	make_iso(int *x , int *y, int z); 

void	render_map(t_map *map);

void	error(void);

void	esc_key_hook(void *param);

t_draw	draw_init(int x0, int y0, int x1, int y1);

#endif
