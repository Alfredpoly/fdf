/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/07 13:52:30 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/07 15:19:28 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(int x, int y, t_arr_map *map)
{
	t_point	point;

	point.x = map->map[y][x][0];
	point.y = map->map[y][x][1];
	point.z = map->map[y][x][2];
	return (point);
}