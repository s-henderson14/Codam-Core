#include "../../fdf.h"

int	file_check(char *filename)
{
	const char *filetype = ".fdf";
	size_t	len;

	len = ft_strlen(filename);
	if ((int)len < 4)
		error();
	if (ft_strncmp(&filename[(int)len - 4], filetype, len) != 0)
		error();
	return (open(filename, O_RDONLY));
}