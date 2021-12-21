/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 14:21:37 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/17 15:29:04 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_draw(t_arr_map map, t_data img)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.row)
	{
		x = 0;
		while (x < map.col - 1)
		{
			draw_line(map, x, y, img);
			x++;
		}
		y++;
	}
	// y = 0;
	// while (y < map.row - 1)
	// {
	// 	x = 0;
	// 	while (x < map.col)
	// 	{
	// 		draw_line_vert(map, x, y, img);
	// 		x++;
	// 	}
	// 	y++;
	// }
}

void	init_line_var(t_arr_map	map, int x, int y, t_line *l)
{
	l->x0 = map.map[y][x][0];
	printf("%d	", l->x0);
	l->y0 = map.map[y][x][1];
	l->x1 = map.map[y][x + 1][0];
	l->y1 = map.map[y][x + 1][1];
	// l->dx = abs(l->x1 - l->x0);
	// l->sx = l->x0 < l->x1 ? 1 : -1;
	// // if (l->x0 < l->x1)
	// // 	l->sx = -1;
	// l->dy = -abs(l->y1 - l->y0);
	// l->sy = l->y0 < l->y1 ? 1 : -1;
	// // if (l->y0 < l->y1)
	// // 	l->sy = -1;
	// l->err = l->dx + l->dy;
}

// t_line	init_line_var_vert(t_arr_map	map, int x, int y, t_line l)
// {
// 	l.x0 = map.map[y][x][0];
// 	l.y0 = map.map[y][x][1];
// 	l.x1 = map.map[y + 1][x][0];
// 	l.y1 = map.map[y + 1][x][1];
// 	l.dx = abs(l.x1 - l.x0);
// 	if (l.x0 < l.x1)
// 		l.sx = 1;
// 	l.dy = -abs(l.y1 - l.y0);
// 	if (l.x0 < l.x1)
// 		l.sy = -1;
// 	l.err = l.dx + l.dy;
// 	return (l);
// }

void	draw_line(t_arr_map	map, int x, int y, t_data img)
{
	t_line	l;

	init_line_var(map, x, y, &l);
	my_mlx_pixel_put(&img, l.x0, l.y0, 0x00FFFFFF);
	// while (1)
	// {
		
		// if (l.x0 == l.x1 && l.y0 == l.y1)
		// 	break ;
		// l.e2 = 2 * l.err;
		// if (l.e2 >= l.dy)
		// {
		// 	l.err += l.dy;
		// 	l.x0 += l.sx;
		// }
		// if (l.e2 <= l.dx)
		// {
		// 	l.err += l.dx;
		// 	l.y0 += l.sy;
		// }
	// }
}

// void	draw_line_vert(t_arr_map map, int x, int y, t_data img)
// {
// 	t_line	l;

// 	init_line_var_vert(map, x, y, l);
// 	while (1)
// 	{
// 		my_mlx_pixel_put(&img, l.x0, l.y0, 0x00FFFFFF);
// 		if (l.x0 == l.x1 && l.y0 == l.y1)
// 			break ;
// 		l.e2 = 2 * l.err;
// 		if (l.e2 >= l.dy)
// 		{
// 			l.err += l.dy;
// 			l.x0 += l.sx;
// 		}
// 		if (l.e2 <= l.dx)
// 		{
// 			l.err += l.dx;
// 			l.y0 += l.sy;
// 		}
// 	}
// }
