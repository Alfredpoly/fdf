/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:44:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/05 15:47:53 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		fdf;
	t_arr_map	map;

	if (argc == 2)
	{
		fdf = init_window();
		fdf.camera = camera_init();
		map = get_file(argv[1]);
		scale(map, 1);
		loop_draw(map, fdf);
		// mlx_key_hook(fdf.win, key_hook, &fdf);
		put_image(fdf);
	}
}
