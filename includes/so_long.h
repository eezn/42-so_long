/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:45:25 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/28 06:03:01 by jin-lee          ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

/* Utils */
void	exit_error(char *message, int flag);

void	read_map(t_game *game, char *pathname);

#endif