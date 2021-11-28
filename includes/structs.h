/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:39:04 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 02:25:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_elem	t_elem;
typedef struct s_tile	t_tile;
typedef struct s_plyr	t_plyr;

struct s_plyr
{
	int	c;
	int	r;
	int	step;
};

struct s_tile
{
	void	*wl;
	void	*ex;
	void	*ax;
	void	*pl;
	void	*co;
	void	*bg;
};

struct s_elem
{
	int	plyr;
	int	coll;
	int	exit;
	int	axit;
	int	wall;
	int	space;
};

struct s_map
{
	int		col;
	int		row;
	char	**map_data;
	t_elem	*elems;
};

struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		width;
	int		height;
	t_tile	tiles;
	t_plyr	plyr;
};

#endif