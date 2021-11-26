/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:37:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 14:32:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check map is rectangular. */

int	is_rectangular(char *line, t_arr *arr)
{
	if (arr->col != ft_strlen(line))
		return (1);
	return (0);
}

/* Check if map is surrounded by walls. */

void	check_is_closed(t_arr *arr)
{
	char	**map;
	int		i;

	map = arr->map_data;
	i = -1;
	while (++i < arr->col)
		if (map[0][i] != '1' || map[arr->row - 1][i] != '1')
			exit_error(ERR_CLOSED, MESSAGE);
	i = -1;
	while (++i < arr->row)
		if (map[i][0] != '1' || map[i][arr->col - 1] != '1')
			exit_error(ERR_CLOSED, MESSAGE);
}

/* Check minimum requirement of component. */

void	check_elem(t_elem *e)
{
	if (e->plyr != 1)
		exit_error(ERR_PLYR, MESSAGE);
	if (e->coll < 1)
		exit_error(ERR_COLL, MESSAGE);
	if (e->exit < 1)
		exit_error(ERR_EXIT, MESSAGE);
}

/* Count a number of each elements and record. */

static void	count_elem(t_elem *elem, char e)
{
	if (e == 'P')
		elem->plyr++;
	if (e == 'C')
		elem->coll++;
	if (e == 'E')
		elem->exit++;
	if (e == '1')
		elem->wall++;
	if (e == '0')
		elem->space++;
}

/* Funtion that will parse map file to check elements and count elements. */

void	parse_map(char *line, char **arr, t_elem *elem, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P' || line[i] == 'C' || line[i] == 'E'
			|| line[i] == '1' || line[i] == '0')
		{
			count_elem(elem, line[i]);
			arr[row][i] = line[i];
			i++;
		}
		else
			exit_error(ERR_ELEM, MESSAGE);
	}
}
