/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:54:39 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:06:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	int	before;

	before = game->plyr.step;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_W || keycode == KEY_UP)
		check_movable(game, UP);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		check_movable(game, DOWN);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		check_movable(game, LEFT);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		check_movable(game, RIGHT);
	if (before != game->plyr.step)
		printf("step: %d\n", game->plyr.step);
	return (0);
}
