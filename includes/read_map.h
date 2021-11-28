/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:10:12 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:12:10 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "./structs.h"

int		open_file(char *pathname);
t_map	*malloc_map(char *pathname);
t_map	*init_map(void);
t_elem	*init_elem(void);

int		is_rectangular(char *line, t_map *map);
void	check_is_closed(t_map *map);
void	check_elem(t_elem *elems);
void	parse_map(char *line, char **map, t_elem *elems, int row);

void	read_map(t_game *game, char *pathname);

#endif