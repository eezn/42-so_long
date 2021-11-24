/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:45:25 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/25 02:20:19 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "./get_next_line.h"
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define MESSAGE 1
# define PERROR 0

# define TRUE 1
# define FALSE 0

typedef struct s_game	t_game;

struct	s_game
{
	void	*mlx;
	void	*win;
};


/*
**Utils
*/
void	exit_error(char *message, int flag);

/*
**
*/
void	check_map(char *pathname);

#endif