/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/05 10:23:05 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/09 12:23:25 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_X 500
# define WINDOW_Y 500
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_A 0
# define ESC 53
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_PLUS 24
# define KEY_MINUS 27

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_line {
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}		t_line;

typedef struct s_camera
{
	double			zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}					t_camera;

typedef struct s_arr_map {
	int			***map;
	int			row;
	int			col;
}				t_arr_map;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct s_data
{
	t_arr_map	map;
	int			row;
	int			col;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		*filename;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_camera	*camera;
}				t_data;

t_data		init_window(void);
void		put_image(t_data img);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_arr_map	get_file(char *filename);
void		scale(t_arr_map map, float scale_val);
void		loop_draw(t_arr_map map, t_data img);
void		draw_line(t_data fdf, t_point f, t_point s);
void		init_brehensam(t_line coor, t_data img);
t_camera	*camera_init(t_data fdf);
int			key_hook(int keycode, t_data *fdf);
t_point		new_point(int x, int y, t_arr_map *map);
t_point		project(t_point p, t_data *fdf);
int			key_press(int key, void *param);
void		rotate(int key, t_data *fdf);
void		move(int key, t_data *fdf);
void		flatten(int key, t_data *fdf);
int			zoom(int keycode, t_data *fdf);
void		loop_brehensam(t_line coor, t_point f, t_point s, t_data fdf);

#endif