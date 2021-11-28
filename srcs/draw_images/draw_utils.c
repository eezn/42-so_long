/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:35:01 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 00:08:08 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_tile(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tiles.wl = mlx_xpm_file_to_image(game->mlx,
			"./images/wall.xpm", &img_width, &img_height);
	game->tiles.ex = mlx_xpm_file_to_image(game->mlx,
			"./images/exit.xpm", &img_width, &img_height);
	game->tiles.ax = mlx_xpm_file_to_image(game->mlx,
			"./images/flower.xpm", &img_width, &img_height);
	game->tiles.pl = mlx_xpm_file_to_image(game->mlx,
			"./images/mario.xpm", &img_width, &img_height);
	game->tiles.co = mlx_xpm_file_to_image(game->mlx,
			"./images/mushroom.xpm", &img_width, &img_height);
	game->tiles.bg = mlx_xpm_file_to_image(game->mlx,
			"./images/back.xpm", &img_width, &img_height);
}

void	put_img(t_game *game, void *ptr, int c, int r)
{
	mlx_put_image_to_window(game->mlx, game->win, ptr,
	(c * TILE_SIZE), (r * TILE_SIZE));
}
