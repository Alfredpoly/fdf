/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/07 14:37:45 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/07 15:04:51 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	if (key == ESC)
		exit(0);
	if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == KEY_Q || key == KEY_A || key == KEY_W
		|| key == KEY_S || key == KEY_E || key == KEY_D)
		rotate(key, fdf);
	else if (key == KEY_R || key == KEY_F)
		flatten(key, fdf);
	return (0);
}