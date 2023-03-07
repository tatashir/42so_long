/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:32:17 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:30 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pre(int argc, char **argv)
{
	int		fd;
	char	*p;

	if (argc != 2)
		exit_error();
	fd = open_file(argv[1]);
	clone(fd);
	p = ft_strchr(argv[1], '.');
	if (ft_strncmp(EXTENTION, p, 5))
		exit_error(ERROR_BER);
}

void	check_map(t_map *map)
{
	int y;
	int row_cnt;

	y = 0;
	map->col = ft_strlen(map->line[y + map->start_row]) -1;
	row_cnt = 0;
	while (y + map->start_row <= map->end_row)
	{
		if (!ft_strncmp(map->line[y + map->start_row], "\n", 1))
			error_map(map->line, map->row, ERROR_CLOSEMAP);
		check_rect_wall();
		check_item();
		y++;
	}
}

void	check_wall(char *s, t_map *map, int y)
{
	int	i;

	if (map->col != (int)ft_strlen(s) -1)
		error_map(map->line, map->row, ERROR_RECT);
	if (y == 0 || y == map->end_row)
	{
		i = 0;
		while (s[i] != '\n')
		{
			if (s[i] != '1')
				error_map(map->line, map->row, ERROR_WALL);
			i++;
		}
	}
	else
	{
		if (s[0] != '1' || s[map->col - 1] != '1')
			error_map(map->line, map->row, ERROR_WALL);
	}
}

