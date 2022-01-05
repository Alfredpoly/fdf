/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: alfred <alfred@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/05 10:23:05 by alfred        #+#    #+#                 */
/*   Updated: 2022/01/05 15:46:27 by alfred        ########   odam.nl         */
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
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15
# define KEY_PLUS 24
# define KEY_MINUS 27

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "getnextline/get_next_line.h"
# include "libft/libft.h"

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
	int				zoom;
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
	int			***map;
	int			row;
	int			col;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
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
void		draw_line(t_data img, int x, int y, t_arr_map map);
void		init_brehensam(t_line coor, t_data img);
t_camera	*camera_init(void);
void		key_hook(int keycode, t_data *fdf);

#endif