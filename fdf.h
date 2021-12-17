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

typedef struct s_line_list
{
	float				x;
	float				y;
	float				z;
	unsigned long		color;
	struct s_line_list	*next;
}				t_line_list;

typedef struct s_arr_map {
	int			**map;
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

t_data	init_window(void);
void	put_image(t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_file(char *filename);

#endif