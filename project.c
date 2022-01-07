/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   project.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/07 14:26:49 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/07 17:13:09 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y - WINDOW_X / 2;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
	*y += WINDOW_X / 2;
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x - WINDOW_X / 2;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
	*x += WINDOW_X / 2;
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;

	previous_x = *x - WINDOW_X / 2;
	*y -= WINDOW_Y / 2;
	*x = previous_x * cos(gamma) - *y * sin(gamma);
	*y = previous_x * sin(gamma) + *y * cos(gamma);
	*x += WINDOW_X / 2;
	*y += WINDOW_Y / 2;
}

t_point	project(t_point p, t_data *fdf)
{
	p.z *= fdf->camera->z_divisor;
	rotate_x(&p.y, &p.z, fdf->camera->alpha);
	rotate_y(&p.x, &p.z, fdf->camera->beta);
	rotate_z(&p.x, &p.y, fdf->camera->gamma);
	p.x += fdf->camera->x_offset;
	p.y += fdf->camera->y_offset;
	return (p);
}
// t_point	project(t_point p, t_data *fdf)
// {
// 	p.x *= fdf->camera->zoom;
// 	p.y *= fdf->camera->zoom;
// 	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
// 	p.x -= (fdf->map.col * fdf->camera->zoom) / 2;
// 	p.y -= (fdf->map.row * fdf->camera->zoom) / 2;
// 	rotate_x(&p.y, &p.z, fdf->camera->alpha);
// 	rotate_y(&p.x, &p.z, fdf->camera->beta);
// 	rotate_z(&p.x, &p.y, fdf->camera->gamma);
// 	p.x += WINDOW_X / 2 + fdf->camera->x_offset ;
// 	p.y += (WINDOW_Y + fdf->map.row * fdf->camera->zoom) / 2
// 		+ fdf->camera->y_offset;
// 	return (p);
// }
