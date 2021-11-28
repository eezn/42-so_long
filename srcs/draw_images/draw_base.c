/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:36:15 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 00:08:25 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_base(t_game *game, int c, int r)
{
	r = -1;
	while (++r < game->map->row)
	{
		c = -1;
		while (++c < game->map->col)
		{
			if (game->map->map_data[r][c] == '1')
				put_img(game, game->tiles.wl, c, r);
			else if (game->map->map_data[r][c] == 'E')
			{
				if (game->map->elems->coll)
					put_img(game, game->tiles.ex, c, r);
				else
				{
					put_img(game, game->tiles.bg, c, r);
					put_img(game, game->tiles.ax, c, r);
				}
			}
			else if (game->map->map_data[r][c] == 'C')
				put_img(game, game->tiles.co, c, r);
			else
				put_img(game, game->tiles.bg, c, r);
		}
	}
}
