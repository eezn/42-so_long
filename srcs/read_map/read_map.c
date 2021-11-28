/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:14 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:00:58 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map(char *pathname, t_map *map, t_elem *elems)
{
	int		fd;
	char	*line;
	int		count;

	fd = open_file(pathname);
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_rectangular(line, map))
			exit_error(ERR_RECT, MESSAGE);
		parse_map(line, map->map_data, elems, count);
		free(line);
		count++;
	}
	free(line);
	close(fd);
	check_elem(elems);
	check_is_closed(map);
}

void	read_map(t_game *game, char *pathname)
{
	t_map	*map;
	t_elem	*elems;

	map = malloc_map(pathname);
	elems = init_elem();
	check_map(pathname, map, elems);
	map->elems = elems;
	game->map = map;
	game->width = map->col * TILE_SIZE;
	game->height = map->row * TILE_SIZE;
}
