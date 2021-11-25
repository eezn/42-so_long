/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:14 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/25 18:06:13 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define ERR_OPEN "\033[33mError: Failed to open the file.\033[0m"
# define ERR_RECT "\033[33mError: Map file is not rectangular.\033[0m"
# define ERR_ELEM "\033[33mError: Invalid elements.\033[0m"

typedef struct s_arr	t_arr;

struct s_arr
{
	int		row;
	int		col;
	char	**map_data;
};

typedef struct s_map	t_map;

struct s_map
{
	int	plyr;
	int	coll;
	int	exit;
	int	wall;
	int space;
};

/* malloc_arr *************************************************************** */

int	open_file(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (!(0 <= fd && fd <= OPEN_MAX))
		exit_error(ERR_OPEN, MESSAGE);
	return (fd);
}

t_arr	*get_size(char *pathname)
{
	t_arr	*arr;
	char	*line;
	int		fd;
	int		line_len;

	fd = open_file(pathname);
	arr = (t_arr *)malloc(sizeof(t_arr));
	arr->col = 0;
	arr->row = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_len = ft_strlen(line);
		if (arr->col < line_len)
			arr->col = line_len;
		arr->row++;
		free(line);
	}
	close(fd);
	return (arr);
}

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

/* ************************************************************************** */

int	is_rectangular(t_arr *arr, char *line)
{
	if (arr->col != ft_strlen(line))
		return (1);
	return (0);
}

void	check_map2(char *pathname, t_arr *arr, t_map *info)
{
	int		fd;
	char	*line;

	fd = open_file(pathname);
	while (get_next_line(fd, &line) > 0)
	{
		// printf("%s\n", line);
		if (is_rectangular(arr, line))
			exit_error(ERR_RECT, MESSAGE);
		free(line);
	}
}

/* ************************************************************************** */

void	check_map(char *pathname)
{
	t_arr	*arr;
	t_map	*info;

	arr = malloc_arr(pathname);	// 이중 배열 free 필요
	check_map2(pathname, arr, info);
}
