/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 09:30:07 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/10 15:04:28 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int f, int s, int current)
{
	double	position;
	double	distance;

	position = current - f;
	distance = s - f;
	return (position / distance);
}

int	gradient(int f, int s, double percentage)
{
	return ((int)((1 - percentage) * f + percentage * s));
}

int	get_color(t_point current, t_point f, t_point s, t_line coor)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (f.color == s.color)
		return (f.color);
	if (coor.dx > coor.dy)
		percentage = percent(f.x, s.x, current.x);
	else
		percentage = percent(f.y, s.y, current.y);
	r = gradient((f.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percentage);
	g = gradient((f.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percentage);
	b = gradient(f.color & 0xFF, s.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
