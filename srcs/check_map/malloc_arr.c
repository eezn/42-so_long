/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:12:21 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 14:26:04 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Function that measures the size of map. */

static t_arr	*get_size(char *pathname)
{
	t_arr	*arr;
	char	*line;
	int		fd;
	int		line_len;

	fd = open_file(pathname);
	arr = init_arr();
	while (get_next_line(fd, &line) > 0)
	{
		line_len = ft_strlen(line);
		if (arr->col < line_len)
			arr->col = line_len;
		arr->row++;
		free(line);
	}
	free(line);
	close(fd);
	return (arr);
}

/* Function that will allocate array to record map data. */

t_arr	*malloc_arr(char *pathname)
{
	t_arr	*arr;
	int		i;

	arr = get_size(pathname);
	arr->map_data = (char **)malloc(sizeof(char *) * arr->row);
	i = 0;
	while (i < arr->row)
		arr->map_data[i++] = (char *)malloc(sizeof(char *) * arr->col);
	return (arr);
}
