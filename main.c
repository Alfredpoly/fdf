/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:44:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/16 13:46:19 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		img;

	if (argc == 2)
	{
		// img = init_window();
		get_file(argv[1]);
		// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		// put_image(img);
	}
}
