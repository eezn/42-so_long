/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:39:04 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/28 05:56:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_elem	t_elem;
typedef	struct s_tile	t_tile;
typedef struct s_img	t_img;
typedef struct s_plyr	t_plyr;

struct s_plyr
{
	int		curr_x;
	int		curr_y;
};

struct s_img
{
	void	*img;
};

struct s_tile
{
	t_img	wl;
	t_img	ex;
	t_img	ax;
	t_img	pl;
	t_img	co;
};

struct s_elem
{
	int	plyr;
	int	coll;
	int	exit;
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
	int		width;		// col * TILE_SIZE
	int		height;		// row * TILE_SIZE
	
	t_tile	tiles;
	t_plyr	plyr;
};

#endif