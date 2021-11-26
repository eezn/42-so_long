/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 15:04:21 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = check_map(argv[1]);
	return (0);
}
