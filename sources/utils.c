/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/07 13:52:30 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/10 14:54:50 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(int x, int y, t_arr_map *map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->color_z[y][x][0];
	point.color = map->color_z[y][x][1];
	return (point);
}

unsigned long	hex_to_deci_color(char *str)
{
	int		decnum;
	int		rem;
	int		i;
	int		len;

	decnum = 0;
	if (!str)
		return (0xFFFFFF);
	len = ft_strlen(str) - 1;
	i = 0;
	while (len >= 2)
	{
		rem = str[len];
		if (rem >= 48 && rem <= 57)
			rem = rem - 48;
		else if (rem >= 65 && rem <= 70)
			rem = rem - 55;
		else if (rem >= 97 && rem <= 102)
			rem = rem - 87;
		else
			return (0);
		decnum = decnum + (rem * pow(16, i++));
		len--;
	}
	return (decnum);
}
