/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:10:12 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 14:32:58 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

typedef struct s_arr	t_arr;
typedef struct s_elem	t_elem;

struct s_arr
{
	int		row;
	int		col;
	char	**map_data;
};

struct s_elem
{
	int	plyr;
	int	coll;
	int	exit;
	int	wall;
	int	space;
};

t_arr	*malloc_arr(char *pathname);

int		open_file(char *pathname);
t_arr	*init_arr(void);
t_elem	*init_elem(void);

int		is_rectangular(char *line, t_arr *arr);
void	check_is_closed(t_arr *arr);
void	check_elem(t_elem *info);
void	parse_map(char *line, char **arr, t_elem *info, int row);

#endif