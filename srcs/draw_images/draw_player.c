/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:37:08 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 00:08:18 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game, int pc, int pr)
{
	int	c;
	int	r;

	r = -1;
	while (++r < game->map->row)
	{
		c = -1;
		while (++c < game->map->col)
		{
			if (game->map->map_data[r][c] == 'C' && r == pr && c == pc)
			{
				game->map->map_data[r][c] = '0';
				put_img(game, game->tiles.bg, c, r);
				put_img(game, game->tiles.pl, pc, pr);
				if (--(game->map->elems->coll) == 0)
					game->map->elems->axit = TRUE;
			}
			else if (game->map->map_data[r][c] == 'E' && r == pr && c == pc)
				exit_success(game);
			else
				put_img(game, game->tiles.pl, pc, pr);
		}
	}
}
