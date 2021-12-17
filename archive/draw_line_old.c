#include "fdf.h"

void	char_zero(void *dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len - 1 && len != 0)
	{
		*(char *)dest = '0';
		i++;
		dest++;
	}
}

int	ft_hexlen(unsigned long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		ret++;
	while (n > 0)
	{
		n = n / 16;
		ret++;
	}
	return (ret);
}

char	*ft_puthex(unsigned long int n)
{
	char	*hex;
	int		d;
	int		i;

	i = ft_hexlen(n) - 1;
	hex = ft_calloc(7, sizeof(char));
	char_zero(hex, 6);
	while (n > 0)
	{
		d = n % 16;
		if (d <= 9)
		{
			hex[i] = d + '0';
			n = n / 16;
		}
		if (d > 9 && d < 16)
		{
			hex[i] = 65 - 10 + d;
			n = n / 16;
		}
		i--;
	}
	return (hex);
}

int	ft_xtoi(const char *str)
{
	int	nb;
	int	i;

	i = ft_strlen(str);
	nb = 0;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * 10 + (str[i] - 55);
		i--;
	}
	return (nb);
}

int	rbg_convert(char *str, int pos)
{
	char	*rgb;

	rgb = malloc(2 * sizeof(char));
	ft_memcpy(rgb, str + pos, 2);
	return (ft_xtoi(rgb));
}

void	draw_line(t_arr_map	*arr_map, t_data img, int i, int j, int v, int unit)
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			x;
	int			y;
	int			x1;
	int			y1;
	char		*color;
	char		*color2;

	x = (int)arr_map->map[i][j]->x;
	y = (int)arr_map->map[i][j]->y;
	x1 = (int)arr_map->map[i + v][j + 1 - v]->x;
	y1 = (int)arr_map->map[i + v][j + 1 - v]->y;
	sx = 1;
	sy = -1;
	dx = x1 - x;
	color = ft_puthex(arr_map->map[i][j]->color);
	color2 = ft_puthex(arr_map->map[i + v][j + 1 - v]->color);
	if (dx < 0)
	{
		dx = dx * -1;
		sx = -1;
	}
	dy = y1 - y;
	if (dy > 0)
	{
		dy = dy * -1;
		sy = 1;
	}
	err = dx + dy;
	while (1)
	{
		if (x >= 0 && x <= WINDOW_X && y >= 0 && y < WINDOW_Y)
			my_mlx_pixel_put(&img, x, y, createRGB(rbg_convert(color, 0), rbg_convert(color, 2), rbg_convert(color, 4)));
		if (x == x1 && y == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}
