/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 19:19:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define TILE_SIZE 64

/* ************************************************************************** */

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	width = game->map->col * TILE_SIZE;
	height = game->map->row * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	init_game(t_game *game)
{
	init_window(game);
}

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	read_map(&game, argv[1]);
	init_game(&game);
	return (0);
}
