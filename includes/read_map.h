/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:10:12 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/27 22:54:30 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "./structs.h"

# define TILE_SIZE 64

t_map	*malloc_map(char *pathname);

int		open_file(char *pathname);
t_map	*init_map(void);
t_elem	*init_elem(void);

int		is_rectangular(char *line, t_map *map);
void	check_is_closed(t_map *map);
void	check_elem(t_elem *elems);
void	parse_map(char *line, char **map, t_elem *elems, int row);

#endif