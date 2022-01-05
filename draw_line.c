/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 14:21:37 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/05 15:48:04 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_draw(t_arr_map map, t_data fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.row)
	{
		x = 0;
		while (x < map.col)
		{
			draw_line(fdf, x, y, map);
			x++;
		}
		y++;
	}
}

void	draw_line(t_data fdf, int x, int y, t_arr_map map)
{
	t_line	coor;

	coor.x0 = map.map[y][x][0];
	coor.y0 = map.map[y][x][1];
	coor.x1 = -1;
	coor.y1 = -1;
	if (x < map.col - 1)
	{
		coor.x1 = map.map[y][x + 1][0];
		coor.y1 = map.map[y][x + 1][1];
	}
	if (!(coor.x1 == -1) || !(coor.y1 == -1))
		init_brehensam(coor, fdf);
	if (y < map.row - 1)
	{
		coor.x1 = map.map[y + 1][x][0];
		coor.y1 = map.map[y + 1][x][1];
	}
	if (!(coor.x1 == -1) || !(coor.y1 == -1))
		init_brehensam(coor, fdf);
}

void	loop_brehensam(t_line coor, t_data fdf)
{
	while (1)
	{
		if (0 < coor.x0 && WINDOW_X > coor.x0
			&& 0 < coor.y0 && WINDOW_Y > coor.y0)
			my_mlx_pixel_put(&fdf, coor.x0, coor.y0, 0xffffff);
		if (coor.x0 == coor.x1 && coor.y0 == coor.y1)
			break ;
		coor.e2 = coor.err;
		if (coor.e2 >- coor.dx)
		{
			coor.err -= coor.dy;
			coor.x0 += coor.sx;
		}
		if (coor.e2 < coor.dy)
		{
			coor.err += coor.dx;
			coor.y0 += coor.sy;
		}
	}
}

void	init_brehensam(t_line coor, t_data fdf)
{
	coor.dx = abs(coor.x1 - coor.x0);
	coor.dy = abs(coor.y1 - coor.y0);
	if (coor.x0 < coor.x1)
		coor.sx = 1;
	else
		coor.sx = -1;
	if (coor.y0 < coor.y1)
		coor.sy = 1;
	else
		coor.sy = -1;
	if (coor.dx > coor.dy)
		coor.err = coor.dx / 2;
	else
		coor.err = -coor.dy / 2;
	loop_brehensam(coor, fdf);
}
