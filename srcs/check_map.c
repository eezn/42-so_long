/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:14 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 14:31:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map2(char *pathname, t_arr *arr, t_elem *elem)
{
	int		fd;
	char	*line;
	int		count;

	fd = open_file(pathname);
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_rectangular(line, arr))
			exit_error(ERR_RECT, MESSAGE);
		parse_map(line, arr->map_data, elem, count);
		free(line);
		count++;
	}
	free(line);
	check_elem(elem);
	check_is_closed(arr);
}

void	check_map(char *pathname)
{
	t_arr	*arr;
	t_elem	*elem;

	arr = malloc_arr(pathname);
	elem = init_elem();
	check_map2(pathname, arr, elem);
}
