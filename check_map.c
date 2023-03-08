/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:32:17 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/08 19:23:54 by tatashir         ###   ########.fr       */
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
	int	y;
	int	row_cnt;

	y = 0;
	map->col = ft_strlen(map->line[y + map->start_row]) - 1;
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

void	check_items(char *s, t_map *map, int y)
{
	static int	i_end_cnt[2];

	while (*s != '\n')
	{
		if (*s != '1' && *s != '0' && *s != 'C' && 
				*s != 'E' &&*s != 'E' && *s != 'P')
			error_map(map->line, map->row, ERROR_ITEM);
		else if (*s == 'C')
			map->c_cnt++;
		else if (*s == 'E')
			i_end_cnt[0]++
	}
}

void	count_mapsize(char *buf, int *set_row)
{
	int	row_cnt;
	int col_cnt;
	char	*tmp;

	row_cnt = 0;
	col_cnt = 0;
	tmp = buf;
	while (*tmp)
	{
		if (*tmp == '\n')
		{
			row_cnt++;
			col_cnt = 0;
		}
		else
			col_cnt++;
		if (col_cnt > MAX_MAP_COL || row_cnt > MAX_FILE_ROW)
		{
			free(buf);
			exit_error(ERROR_BIG_MAP);			
		}
		tmp++;
	}
	*set_row = row_cnt;
}
