/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:58:24 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/25 02:19:37 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message, int flag)
{
	if (flag == MESSAGE)
		ft_putendl_fd(message, STDERR_FILENO);
	if (flag == PERROR)
		perror(message);
	exit(EXIT_FAILURE);
}
