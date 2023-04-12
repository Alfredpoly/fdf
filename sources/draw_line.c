/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 14:21:37 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/10 15:03:23 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_data fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_X)
	{
		y = 0;
		while (y < WINDOW_Y)
		{
			my_mlx_pixel_put(&fdf, x, y, 0);
			y++;
		}
		x++;
	}
}

void	loop_draw(t_arr_map map, t_data fdf)
{
	int	x;
	int	y;

	background(fdf);
	y = 0;
	while (y < map.row)
	{
		x = 0;
		while (x < map.col)
		{
			if (x < fdf.map.col - 1)
			{
				draw_line(fdf, project(new_point(x, y, &map), &fdf),
					project(new_point(x + 1, y, &map), &fdf));
			}
			if (y < fdf.map.row - 1)
			{
				draw_line(fdf, project(new_point(x, y, &map), &fdf),
					project(new_point(x, y + 1, &map), &fdf));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
}

void	draw_line(t_data fdf, t_point f, t_point s)
{
	t_line	coor;

	coor.dx = abs(s.x - f.x);
	coor.dy = abs(s.y - f.y);
	if (f.x < s.x)
		coor.sx = 1;
	else
		coor.sx = -1;
	if (f.y < s.y)
		coor.sy = 1;
	else
		coor.sy = -1;
	if (coor.dx > coor.dy)
		coor.err = coor.dx / 2;
	else
		coor.err = -coor.dy / 2;
	loop_brehensam(coor, f, s, fdf);
}

void	loop_brehensam(t_line coor, t_point f, t_point s, t_data fdf)
{
	t_point	cur;

	cur.x = f.x;
	cur.y = f.y;
	while (1)
	{
		if (0 < cur.x && WINDOW_X > cur.x
			&& 0 < cur.y && WINDOW_Y > cur.y)
			my_mlx_pixel_put(&fdf, cur.x, cur.y, get_color(cur, f, s, coor));
		if (cur.x == s.x && cur.y == s.y)
			break ;
		coor.e2 = coor.err;
		if (coor.e2 > -coor.dx)
		{
			coor.err -= coor.dy;
			cur.x += coor.sx;
		}
		if (coor.e2 < coor.dy)
		{
			coor.err += coor.dx;
			cur.y += coor.sy;
		}
	}
}
