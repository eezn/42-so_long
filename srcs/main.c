/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/28 03:35:21 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	init_tile(t_game *game)
{
	int	img_width;
	int	img_height;

	game->tiles.wl.img = mlx_xpm_file_to_image(game->mlx,
		"./images/wall.xpm", &img_width, &img_height);
	game->tiles.ex.img = mlx_xpm_file_to_image(game->mlx,
		"./images/exit.xpm", &img_width, &img_height);
	game->tiles.ax.img = mlx_xpm_file_to_image(game->mlx,
		"./images/flower.xpm", &img_width, &img_height);
	game->tiles.pl.img = mlx_xpm_file_to_image(game->mlx,
		"./images/mario.xpm", &img_width, &img_height);
	game->tiles.co.img = mlx_xpm_file_to_image(game->mlx,
		"./images/mushroom.xpm", &img_width, &img_height);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_tile(game);
}

/* ************************************************************************** */

void	print_map_terminal(t_game *game)
{
	int	r;
	int c;
	
	printf("width  : %d\nheight : %d\n", game->width, game->height);
	r = -1;
	while (++r < game->map->row)
	{
		int c = -1;
		while (++c < game->map->col)
			printf("%c", game->map->map_data[r][c]);
		printf("\n");
	}
}

void	main_loop(t_game *game)
{
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	read_map(&game, argv[1]);
	init_game(&game);
		
	print_map_terminal(&game);

	int r = -1;
	while (++r < game.map->row)
	{
		int c = -1;
		while (++c < game.map->col)
		{
			if (game.map->map_data[r][c] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.tiles.wl.img, (c * TILE_SIZE), (r * TILE_SIZE));
			if (game.map->map_data[r][c] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.tiles.ex.img, (c * TILE_SIZE), (r * TILE_SIZE));
			if (game.map->map_data[r][c] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.tiles.pl.img, (c * TILE_SIZE), (r * TILE_SIZE));
			if (game.map->map_data[r][c] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.tiles.co.img, (c * TILE_SIZE), (r * TILE_SIZE));
		}
	}
	main_loop(&game);
	
	return (0);
}
