/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:44:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/17 15:20:25 by fpolycar      ########   odam.nl         */
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
		scale(map, 1.2);
		loop_draw(map, img);
		// put_image(img);
	}
}
