/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:02:32 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/08 19:14:58 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//ERROR
# define ERRPR_ARGS	"not args 2"
# define ERROR_BER	"not ber file"

//const
#define EXTENTION ".ber"

typedef struct s_solong{
	void
	void
};	t_solong

typedef struct s_map{
	int	fd;
	char	*filepath;
	char	**line;
	int		start_row;
	int 	end_row;
	int 	c_cnt;
	int		row;
	int		col;
};	t_map

#endif