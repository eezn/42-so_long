/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/28 06:02:21 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/* ************************************************************************** */

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

void	init_plyr(t_game *game)
{
	game->plyr.curr_x = 10;
	game->plyr.curr_y = 10;
	printf("%d, %d\n", game->plyr.curr_x, game->plyr.curr_y);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_tile(game);
	init_plyr(game);
}

void	draw_base(t_game *game)
{
	int r;
	int c;
	
	r = -1;
	while (++r < game->map->row)
	{
		c = -1;
		while (++c < game->map->col)
		{
			if (game->map->map_data[r][c] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
				game->tiles.wl.img, (c * TILE_SIZE), (r * TILE_SIZE));
			if (game->map->map_data[r][c] == 'E')
			{
				if (game->map->elems->coll)
					mlx_put_image_to_window(game->mlx, game->win,
					game->tiles.ex.img, (c * TILE_SIZE), (r * TILE_SIZE));
				else
					mlx_put_image_to_window(game->mlx, game->win,
					game->tiles.ax.img, (c * TILE_SIZE), (r * TILE_SIZE));
			}
		}
	}
}

int	main_loop(t_game *game)
{
	draw_base(game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W || keycode == KEY_UP)
		game->plyr.curr_x++;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->plyr.curr_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->plyr.curr_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		game->plyr.curr_y--;
	else
		pass();
	printf("%d, %d\n", game->plyr.curr_x, game->plyr.curr_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	read_map(&game, argv[1]);
	print_map_terminal(&game);
	
	init_game(&game);
		
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	
	return (0);
}
