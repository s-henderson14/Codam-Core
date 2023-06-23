/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenders <shenders@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:58:13 by shenders          #+#    #+#             */
/*   Updated: 2023/06/23 20:01:32 by shenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	file_check(char *filename)
{
	const char	*filetype = ".fdf";
	size_t		len;

	len = ft_strlen(filename);
	if ((int)len < 4)
		error();
	if (ft_strncmp(&filename[(int)len - 4], filetype, len) != 0)
		error();
	return (open(filename, O_RDONLY));
}
