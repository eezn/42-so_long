/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/25 02:20:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# define ERR_ARGS "\033[33mUsage: ./so_long <pathname>\033[0m"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERR_ARGS, MESSAGE);
	check_map(argv[1]);
	return (0);
}
