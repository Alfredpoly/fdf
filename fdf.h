#ifndef FDF_H
# define FDF_H
# define WINDOW_X 1000
# define WINDOW_Y 1000

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "getnextline/get_next_line.h"
# include "libft/libft.h"

typedef struct s_line {
	int dx;
	int dy;
  	int err;
	int sx;
	int sy;
	int e2;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}			t_line;

typedef struct s_arr_map {
	int			***map;
	int			row;
	int			col;
}				t_arr_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_data		init_window(void);
void		put_image(t_data img);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_arr_map	get_file(char *filename);
void		scale(t_arr_map map, float scale_val);
void		loop_draw(t_arr_map map, t_data img);
void		draw_line(t_arr_map	map, int x, int y, t_data img);
void		draw_line_vert(t_arr_map	map, int x, int y, t_data img);

#endif