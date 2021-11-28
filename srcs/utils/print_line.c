/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:20:27 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 00:23:02 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_line(int col)
{
	int	i;

	i = 0;
	while (i++ < col)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	nl();
}
