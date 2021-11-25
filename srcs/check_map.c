/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:14 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/25 19:18:12 by jin-lee          ###   ########.fr       */
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

t_map	*init_info(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	if (!ret)
		return (NULL);
	ret->plyr = 0;
	ret->coll = 0;
	ret->exit = 0;
	ret->wall = 0;
	ret->space = 0;
	return (ret);
}

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

int	is_rectangular(char *line, t_arr *arr)
{
	if (arr->col != ft_strlen(line))
		return (1);
	return (0);
}

void	count_elem(t_map *info, char elem)
{
	if (elem == 'P')
		info->plyr++;
	if (elem == 'C')
		info->coll++;
	if (elem == 'E')
		info->exit++;
	if (elem == '1')
		info->wall++;
	if (elem == '0')
		info->space++;
}

void	parse_map(char *line, char **arr, t_map *info, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P' || line[i] == 'C' || line[i] == 'E' ||
			line[i] == '1' || line[i] == '0')
		{
			count_elem(info, line[i]);
			arr[row][i] = line[i];
			i++;
		}
		else
			exit_error(ERR_ELEM, MESSAGE);
	}
}

void	check_map2(char *pathname, t_arr *arr, t_map *info)
{
	int		fd;
	char	*line;
	int		count;

	fd = open_file(pathname);
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		// printf("%s\n", line);
		if (is_rectangular(line, arr))
			exit_error(ERR_RECT, MESSAGE);
		parse_map(line, arr->map_data, info, count);
		free(line);
		count++;
	}
}

/* ************************************************************************** */

void	check_map(char *pathname)
{
	t_arr	*arr;
	t_map	*info;

	arr = malloc_arr(pathname);
	info = init_info();
	check_map2(pathname, arr, info);

	/* Print array */
	// nl();
	// int i = 0;
	// while (i < arr->row)
	// {
	// 	int j = 0;
	// 	while (j < arr->col)
	// 		printf("%c ", arr->map_data[i][j++]);
	// 	printf("\n");
	// 	i++;
	// }

	/* Print info */
	// nl();
	// printf("P: %d\n", info->plyr);
	// printf("C: %d\n", info->coll);
	// printf("E: %d\n", info->exit);
	// printf("1: %d\n", info->wall);
	// printf("0: %d\n", info->space);
}
