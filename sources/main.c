/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:44:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/12 16:05:45 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data		fdf;

	if (argc == 2)
	{
		fdf = init_window();
		fdf.map = get_file(argv[1]);
		fdf.camera = camera_init(fdf);
		mlx_hook(fdf.win, 2, 0, key_press, &fdf);
		mlx_hook(fdf.win, 17, 0, close_win, &fdf);
		loop_draw(fdf.map, fdf);
		mlx_loop(fdf.mlx);
	}
}
