/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/05 13:11:09 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/05 15:46:11 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(int keycode, t_data *fdf)
{
	if (keycode == ARROW_UP)
        fdf->camera->zoom += 45;
	// loop_draw
}
