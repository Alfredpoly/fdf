/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 11:00:28 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/17 10:44:49 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(t_arr_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			free(map->color_z[y][x]);
			x++;
		}
		free(map->color_z[y]);
		y++;
	}
	free(map->color_z);
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

void	init_arr(t_arr_map *map, int y)
{
	if (y == 0)
	{
		map->color_z = (int ***)malloc(map->row * sizeof(int **));
		if (!map->color_z)
			free_arr(map);
	}
}

void	get_char_in_line(char *str, int y, t_arr_map *map)
{
	char	**value;
	char	**color;
	int		x;

	value = ft_split(str, ' ');
	x = 0;
	init_arr(map, y);
	while (value[x] && value[x][0] != '\n')
	{
		map->color_z[y] = (int **)malloc(map->col * sizeof(int *));
		if (!map->color_z[y])
			free_arr(map);
		while (value[x])
		{
			if (value[x][0] == '\n')
				break ;
			map->color_z[y][x] = (int *)malloc(2 * sizeof(int));
			if (!map->color_z[y][x])
				free_arr(map);
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
