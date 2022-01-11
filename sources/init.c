/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:43:21 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/11 13:21:37 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	init_window(void)
{
	t_data	fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WINDOW_X, WINDOW_Y, "fdf");
	fdf.img = mlx_new_image(fdf.mlx, WINDOW_X, WINDOW_Y);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, &fdf.line_length,
			&fdf.endian);
	return (fdf);
}

t_camera	*camera_init(t_data fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	if (WINDOW_X / fdf.map.col / 2 <= WINDOW_Y / fdf.map.row / 2)
		camera->zoom = WINDOW_X / fdf.map.col / 2;
	else
		camera->zoom = WINDOW_Y / fdf.map.row / 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 3;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
