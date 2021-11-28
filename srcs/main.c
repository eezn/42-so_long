/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:00:46 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_start_position(t_game *game, int c, int r)
{
	nl();
	print_line(game->map->col);
	r = -1;
	while (++r < game->map->row)
	{
		c = -1;
		while (++c < game->map->col)
		{
			printf("%c ", game->map->map_data[r][c]);
			if (game->map->map_data[r][c] == 'P')
			{
				game->plyr.c = c;
				game->plyr.r = r;
				game->plyr.step = 0;
			}
		}
		printf("\n");
	}
	print_line(game->map->col);
	printf("\033[35m\n -> Start game\n\n\033[0m");
}

/* ************************************************************************** */

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	init_game(t_game *game)
{
	init_window(game);
	init_tile(game);
}

int	main_loop(t_game *game)
{
	draw_base(game, 0, 0);
	draw_player(game, game->plyr.c, game->plyr.r);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	read_map(&game, argv[1]);
	get_start_position(&game, 0, 0);
	init_game(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
