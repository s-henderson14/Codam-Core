#include "../../fdf.h"

t_draw	draw_init(int x0, int y0, int x1, int y1)
{
	t_draw	line_data;

	line_data.x0 = x0;
	line_data.y0 = y0;
	line_data.x1 = x1;
	line_data.y1 = y1;
	line_data.x_diff = ft_abs(x1 - x0);
	line_data.y_diff = ft_abs(y1 - y0);
	line_data.error = line_data.x_diff - line_data.y_diff;
	return (line_data);
}