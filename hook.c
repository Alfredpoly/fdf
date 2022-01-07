/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/05 13:11:09 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/07 16:36:18 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_data *fdf)
{
	if (key == KEY_Q)
		fdf->camera->alpha += 0.05;
	else if (key == KEY_A)
		fdf->camera->alpha -= 0.05;
	else if (key == KEY_W)
		fdf->camera->beta -= 0.05;
	else if (key == KEY_S)
		fdf->camera->beta += 0.05;
	else if (key == KEY_E)
		fdf->camera->gamma += 0.05;
	else if (key == KEY_D)
		fdf->camera->gamma -= 0.05;
	fdf->map = get_file(fdf->filename);
	loop_draw(fdf->map, *fdf);
}

void	move(int key, t_data *fdf)
{
	if (key == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->camera->y_offset -= 10;
	else
		fdf->camera->y_offset += 10;
	fdf->map = get_file(fdf->filename);
	loop_draw(fdf->map, *fdf);
}

void	flatten(int key, t_data *fdf)
{
	if (key == KEY_F)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_R)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	fdf->map = get_file(fdf->filename);
	loop_draw(fdf->map, *fdf);
}

int	zoom(int keycode, t_data *fdf)
{
	if (keycode == KEY_PLUS)
	{
		fdf->camera->zoom = fdf->camera->zoom / 1.1;
	}
	if (keycode == KEY_MINUS)
	{
		fdf->camera->zoom = fdf->camera->zoom * 1.1;
	}
	fdf->map = get_file(fdf->filename);
	loop_draw(fdf->map, *fdf);
	return (0);
}
