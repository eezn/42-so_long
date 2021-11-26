/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:12:21 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 14:59:59 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Function that measures the size of map. */

static t_map	*get_size(char *pathname)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		line_len;

	fd = open_file(pathname);
	map = init_map();
	while (get_next_line(fd, &line) > 0)
	{
		line_len = ft_strlen(line);
		if (map->col < line_len)
			map->col = line_len;
		map->row++;
		free(line);
	}
	free(line);
	close(fd);
	return (map);
}

/* Function that will allocate array to record map data. */

t_map	*malloc_map(char *pathname)
{
	t_map	*map;
	int		i;

	map = get_size(pathname);
	map->map_data = (char **)malloc(sizeof(char *) * map->row);
	i = 0;
	while (i < map->row)
		map->map_data[i++] = (char *)malloc(sizeof(char *) * map->col);
	return (map);
}
