/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:45:25 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:12:21 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "./error_message.h"
# include "./structs.h"
# include "./key.h"
# include "./read_map.h"

# define TILE_SIZE 64
# define TRUE 1
# define FALSE 0

/* Utils */
int		exit_game(t_game *game);
void	exit_success(t_game *game);
void	exit_error(char *message, int flag);
void	print_line(int col);

/* Draw Window */
void	init_tile(t_game *game);
void	put_img(t_game *game, void *ptr, int c, int r);
void	draw_base(t_game *game, int c, int r);
void	draw_player(t_game *game, int pc, int pr);

#endif