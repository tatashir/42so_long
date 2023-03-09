/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:34:38 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/09 22:36:22 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_array(char **line, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        free(line[i]);
        i++;
    }
    free(line);
}

void    exit_error(const char *m)
{
    print_error_msg(m);
    exit(0);
}
