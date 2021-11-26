/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:45:25 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 19:17:50 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "./get_next_line.h"
# include "./read_map.h"
# include "./error_message.h"
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define TRUE 1
# define FALSE 0

typedef struct s_game	t_game;

struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
};

/* Utils */
void	exit_error(char *message, int flag);

void	read_map(t_game *game, char *pathname);

#endif