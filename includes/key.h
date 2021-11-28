/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 01:45:38 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:05:45 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "./struct.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC			53

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124

/* Flags */
# define UP	1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

int		key_press(int keycode, t_game *game);
void	check_movable(t_game *game, int dir);

#endif