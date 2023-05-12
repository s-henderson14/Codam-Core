#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct 
{
	int	width;
	int	height;
	int	**altitude;

	mlx_t		*mlx_ptr;
	mlx_image_t	*img_ptr;
}			fdf;

int		map_height(char *map);

int		map_width(char *map);

int		x_dir(int x_start, int x_end);

int		y_dir(int y_stat, int y_end);

void	draw_line(int x_start, int y_start, int x_end, int y_end, fdf *map);

void	parse_map(fdf *map, char *file);

void	place_coordinate(int *altitude, char *row);


#endif
