#include "../../fdf.h"

void	clean_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clear_array(t_map *map, int **points)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (points != NULL)
			free(points[y]);
		y++;
	}
	free(points);
}

void	clear_array1(int **points)
{
	int	i;

	i = 0;
	while (points[i])
	{
		if (points != NULL)
			free(points[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}