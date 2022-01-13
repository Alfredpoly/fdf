/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 11:00:28 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/12 16:07:20 by alfred        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(t_arr_map *map)
{
	int	x;
	int	y;
	int	val;

	y = 0;
	while (y < map->row)
	{
		free(map->color_z[y]);
		x = 0;
		while (x < map->row)
		{
			free(map->color_z[y][x]);
			val = 0;
			while (val < 2)
			{
				free(map->color_z[y][x]);
				val++;
			}
			x++;
		}
		y++;
	}
}

void	col_row(char *filename, t_arr_map *map)
{
	char		**value;
	char		**color;
	char		*str;
	int			fd;

	map->row = 0;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		map->col = 0;
		value = ft_split(str, ' ');
		while (value[map->col])
		{
			color = ft_split(value[map->col], ',');
			if (color[0][0] == '\n')
				break ;
			map->col++;
		}
		str = get_next_line(fd);
		map->row++;
	}
}

void	get_char_in_line(char *str, int y, t_arr_map *map)
{
	char	**value;
	char	**color;
	int		x;

	value = ft_split(str, ' ');
	x = 0;
	if (y == 0)
		map->color_z = (int ***)malloc(map->row * sizeof(int **));
	while (value[x] && value[x][0] != '\n')
	{
		map->color_z[y] = (int **)malloc(map->col * sizeof(int *));
		while (value[x])
		{
			if (value[x][0] == '\n')
				break ;
			map->color_z[y][x] = (int *)malloc(2 * sizeof(int));
			color = ft_split(value[x], ',');
			map->color_z[y][x][0] = ft_atoi(value[x]);
			map->color_z[y][x][1] = hex_to_deci_color(color[1]);
			x++;
		}
	}
}

t_arr_map	get_file(char *filename)
{
	int			fd;
	char		*str;
	int			y;
	t_arr_map	map;

	y = 0;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	col_row(filename, &map);
	while (str)
	{
		get_char_in_line(str, y, &map);
		str = get_next_line(fd);
		y++;
	}
	return (map);
}
