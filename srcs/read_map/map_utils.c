/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:18:05 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/26 15:00:30 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (!(0 <= fd && fd <= OPEN_MAX))
		exit_error(ERR_OPEN, MESSAGE);
	return (fd);
}

t_map	*init_map(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	ret->col = 0;
	ret->row = 0;
	ret->map_data = NULL;
	return (ret);
}

t_elem	*init_elem(void)
{
	t_elem	*ret;

	ret = (t_elem *)malloc(sizeof(t_elem));
	if (!ret)
		return (NULL);
	ret->plyr = 0;
	ret->coll = 0;
	ret->exit = 0;
	ret->wall = 0;
	ret->space = 0;
	return (ret);
}
