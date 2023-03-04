/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:32:17 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/04 17:53:12 by tatashir         ###   ########.fr       */
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
		if (!ft_strncmp(map->line[]))
	}
}
