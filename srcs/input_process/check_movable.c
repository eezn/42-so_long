/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:54:26 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:08:45 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_movable_up(t_game *game, int tmp_c, int tmp_r)
{
	char	elem;

	elem = game->map->map_data[--tmp_r][tmp_c];
	if (!(elem == '1' || (elem == 'E' && !game->map->elems->axit)))
	{
		game->plyr.r = tmp_r;
		game->plyr.step++;
	}
}

static void	check_movable_down(t_game *game, int tmp_c, int tmp_r)
{
	char	elem;

	elem = game->map->map_data[++tmp_r][tmp_c];
	if (!(elem == '1' || (elem == 'E' && !game->map->elems->axit)))
	{
		game->plyr.r = tmp_r;
		game->plyr.step++;
	}
}

static void	check_movable_left(t_game *game, int tmp_c, int tmp_r)
{
	char	elem;

	elem = game->map->map_data[tmp_r][--tmp_c];
	if (!(elem == '1' || (elem == 'E' && !game->map->elems->axit)))
	{
		game->plyr.c = tmp_c;
		game->plyr.step++;
	}
}

static void	check_movable_right(t_game *game, int tmp_c, int tmp_r)
{
	char	elem;

	elem = game->map->map_data[tmp_r][++tmp_c];
	if (!(elem == '1' || (elem == 'E' && !game->map->elems->axit)))
	{
		game->plyr.c = tmp_c;
		game->plyr.step++;
	}
}

void	check_movable(t_game *game, int dir)
{
	if (dir == UP)
		check_movable_up(game, game->plyr.c, game->plyr.r);
	if (dir == DOWN)
		check_movable_down(game, game->plyr.c, game->plyr.r);
	if (dir == LEFT)
		check_movable_left(game, game->plyr.c, game->plyr.r);
	if (dir == RIGHT)
		check_movable_right(game, game->plyr.c, game->plyr.r);
}
