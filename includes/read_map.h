/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:10:12 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 17:01:06 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

typedef struct s_map	t_map;
typedef struct s_elem	t_elem;

struct s_map
{
	int		row;
	int		col;
	char	**map_data;
	t_elem	*elems;
};

struct s_elem
{
	int	plyr;
	int	coll;
	int	exit;
	int	wall;
	int	space;
};

t_map	*malloc_map(char *pathname);

int		open_file(char *pathname);
t_map	*init_map(void);
t_elem	*init_elem(void);

int		is_rectangular(char *line, t_map *map);
void	check_is_closed(t_map *map);
void	check_elem(t_elem *elems);
void	parse_map(char *line, char **map, t_elem *elems, int row);

#endif