/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 11:00:28 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/17 11:18:57 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	col_row(char *filename, t_arr_map *map)
{
	char		**value;
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
			if (value[map->col][0] == '\n')
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
	int		x;

	value = ft_split(str, ' ');
	x = 0;
	if (y == 0)
		map->map = (int ***)malloc(map->row * sizeof(int **));
	while (value[x] && value[x][0] != '\n')
	{
		map->map[y] = (int **)malloc(map->col * sizeof(int *));
		while (value[x])
		{
			if (value[x][0] == '\n')
				break ;
			map->map[y][x] = (int *)malloc(3 * sizeof(int));
			map->map[y][x][0] = x;
			map->map[y][x][1] = y;
			map->map[y][x][2] = ft_atoi(value[x]);
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
