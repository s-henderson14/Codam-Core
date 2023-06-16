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

void	clean_array(int **points, t_map *map)
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