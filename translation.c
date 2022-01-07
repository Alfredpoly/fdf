/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 11:19:38 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/07 13:27:45 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(float unit, t_arr_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.row)
	{
		x = 0;
		while (x < map.col)
		{
			map.map[y][x][2] = (map.map[y][x][2] * unit);
			map.map[y][x][0] = (WINDOW_X / 2) + (map.map[y][x][0])
				- (map.col * unit / 4) + (map.row * unit / 4);
			map.map[y][x][1] = (WINDOW_Y / 2) + (map.map[y][x][1]) / 2
				- ((map.col + map.row) * unit / 8) - (map.map[y][x][2] / 15);
			x++;
		}
		y++;
	}
}

void	isometric(float unit, t_arr_map map)
{
	float		tmp;
	int			x;
	int			y;

	y = 0;
	while (y < map.row)
	{
		x = 0;
		while (x < map.col)
		{
			tmp = map.map[y][x][0];
			map.map[y][x][0] = (map.map[y][x][0] - map.map[y][x][1]) * unit / 2;
			map.map[y][x][1] = (tmp + map.map[y][x][1]) * unit / 2;
			x++;
		}
		y++;
	}
	center(unit, map);
}

void	scale(t_arr_map map, float scale_val)
{
	float		unitx;
	float		unity;

	unitx = WINDOW_X / (scale_val * map.col);
	unity = WINDOW_Y / (scale_val * map.row);
	if (unitx > unity)
		isometric(unity, map);
	else
		isometric(unitx, map);
}
