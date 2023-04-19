#include "../include/MLX42/MLX42.h"
#include <unistd.h>

mlx_closefunc close_window()
{	
	write(1, "Window Closed\n", 14);
	return (0);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = mlx_init(1000, 1000, "Hello, World!", false);
	img = mlx_new_image(mlx, 500, 500);
	while (x != 500)
		mlx_put_pixel(img, x++, 250, 0xFFFFFF);
	while (y != 500)
		mlx_put_pixel(img, 250, y++, 0xFFFFFF);
	mlx_image_to_window(mlx , img, 250, 250);
	mlx_loop(mlx);
	mlx_close_hook(mlx, close_window(),);
	mlx_terminate(mlx);
	return (0);
}
