/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:37:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 00:35:23 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check map is rectangular. */

int	is_rectangular(char *line, t_map *map)
{
	if (map->col != (int)ft_strlen(line))
		return (1);
	return (0);
}

/* Check if map is surrounded by walls. */

void	check_is_closed(t_map *map)
{
	char	**arr;
	int		i;

	arr = map->map_data;
	i = -1;
	while (++i < map->col)
		if (arr[0][i] != '1' || arr[map->row - 1][i] != '1')
			exit_error(ERR_CLOSED, MESSAGE);
	i = -1;
	while (++i < map->row)
		if (arr[i][0] != '1' || arr[i][map->col - 1] != '1')
			exit_error(ERR_CLOSED, MESSAGE);
}

/* Check minimum requirement of component. */

void	check_elem(t_elem *elems)
{
	if (elems->plyr != 1)
		exit_error(ERR_PLYR, MESSAGE);
	if (elems->coll < 1)
		exit_error(ERR_COLL, MESSAGE);
	if (elems->exit < 1)
		exit_error(ERR_EXIT, MESSAGE);
}

/* Count a number of each elements and record. */

static void	count_elem(t_elem *elems, char elem)
{
	if (elem == 'P')
		elems->plyr++;
	if (elem == 'C')
		elems->coll++;
	if (elem == 'E')
		elems->exit++;
	if (elem == '1')
		elems->wall++;
	if (elem == '0')
		elems->space++;
}

/* Funtion that will parse map file to check elements and count elements. */

void	parse_map(char *line, char **map, t_elem *elems, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P' || line[i] == 'C' || line[i] == 'E'
			|| line[i] == '1' || line[i] == '0')
		{
			count_elem(elems, line[i]);
			map[row][i] = line[i];
			i++;
		}
		else
			exit_error(ERR_ELEM, MESSAGE);
	}
}
