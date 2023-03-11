/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:18:37 by tatashir          #+#    #+#             */
/*   Updated: 2023/03/11 22:07:24 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    input_file(t_map *map, char *filepath)
{
    int i;

    map->filepath = filepath;
    get_ncount(map);
    if (!map->row)
        exit_error(ERROR_EMPTY);
    map->fd = open_file(map->filepath);
    map->line = malloc(sizeof(char *) * map->row);
    if (map->line == NULL)
        exit_error(ERROR_MALLOC);
    map->c_cnt = 0;
    i = 0;
    while (i < map->row)
    {
        map->line[i] = get_next_line(map->fd);
        if (map->line[i] == NULL)
            error_malloc_array(map->line, i);
        i++;
    }
    set_map_row(map);
}

void    get_ncount(t_map *map)
{
    int     buf_size;
    char    *buf;

    map->fd = open_file(map->filepath);
    buf_size = (MAX_FILE_ROW + 1) * (MAX_SIZE_COL + 1);
    buf = malloc(sizeof(char) * buf_size);
    if (buf == NULL)
        exit_error(ERROR_MALLOC);
    if (read(map->fd, buf, buf_size) == -1)
        exit_error(ERROR_READ);
    set_nrow_check_map_size(buf, &map->row);
    free(buf);
    close(map->fd);
}

int open_file(char *filepath)
{
    int fd;

    fd = open(filepath, O_READONLY);
    if (fd == -1);
    {
        printf_error_msg(ERROR_FILE);
        exit(0);
    }
    return (fd);
}

void    find_map_row(t_map *map)
{
    int i;

    i = 0;
    while (!ftstrncmp(map->line[i], "\n", 1))
    {
        
    }
}