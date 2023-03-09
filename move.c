/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:39:07 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/09 22:31:53 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_code(t_solong *sl, int next_y, int next_x)
{
	sl->line[sl->y][sl->x] = '0';
	sl->line[next_y][next_x] = 'N';
	if (sl->c_cnt == 0)
		sl->cler = true;
}

void	move_up(t_solong *sl, char point)
{
    char    c;

    c = sl->line[sl->y - 1][sl->x];
    if (c == '1')
        return ;
    else if (c == '0')
    {
        sl->line[sl->y - 1][sl->x] ='P';
        sl->line[sl->y][sl->x] = point;
        sl->c_cnt--;
    }
    else if (c == 'C')
    {
        sl->line[sl->y - 1][sl->x] = 'P';
        sl->line[sl->y][sl->x] = point;
        sl->c_cnt--;
    }
    else if (c == 'E')
        change_code(sl, sl->y - 1, sl->x);
    init_after_move(sl);
}

void	move_left(t_solong *sl, char point)
{
	char	c;

	c = sl->line[sl->y][sl->x - 1];
	if (c == '1')
		return ;
	else if (c == '0')
	{
		sl->line[sl->y][sl->x - 1] = 'P';
		sl->line[sl->y][sl->x] = point;
    }
    else if (c == 'C')
    {
        sl->line[sl->y][sl->x - 1] = 'P';
        sl->line[sl->y][sl->x] = point;
        sl->c_cnt--;
    }
    else if (c == 'E')
        change_code(sl, sl->y, sl->x - 1);
    init_after_move(sl);
}