/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:44:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/17 11:51:18 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		img;
	t_arr_map	map;
	int			x;
	int			y;

	if (argc == 2)
	{
		// img = init_window();
		map = get_file(argv[1]);
		scale(map, 2);
		y = 0;
		while (y < map.col)
		{
			x = 0;
			while (x < map.row)
			{
				printf("%d %d %d		", map.map[y][x][0], map.map[y][x][1], map.map[y][x][2]);
				x += 1;
			}
			y++;
		}
		// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		// put_image(img);
	}
}
