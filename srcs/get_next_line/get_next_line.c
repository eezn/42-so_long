/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:39:50 by jin-lee           #+#    #+#             */
/*   Updated: 2021/03/19 22:45:49 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_result(char **line, char **archive_fd, int idx)
{
	char			*cut_before;
	char			*cut_after;

	if (idx < 0)
	{
		free(*archive_fd);
		*archive_fd = NULL;
		return (-1);
	}
	if (ft_strchr(*archive_fd, '\n') == NULL)
	{
		*line = *archive_fd;
		*archive_fd = NULL;
		return (0);
	}
	cut_before = *archive_fd;
	while (**archive_fd != '\n')
		(*archive_fd)++;
	**archive_fd = 0;
	cut_after = ++(*archive_fd);
	*line = ft_strdup(cut_before);
	*archive_fd = ft_strdup(cut_after);
	free(cut_before);
	return (1);
}

char	*attach_buf(char *archive_fd, char *buf)
{
	char			*ret;

	if (archive_fd)
		ret = ft_strjoin(archive_fd, buf);
	else
		ret = ft_strdup(buf);
	free(archive_fd);
	return (ret);
}

char	*init_archive(void)
{
	char			*init;

	init = (char *)malloc(sizeof(char));
	if (!init)
		return (NULL);
	*init = 0;
	return (init);
}

int	get_next_line(int fd, char **line)
{
	static char		*archive[OPEN_MAX + 1];
	char			*chk_buf;
	char			*line_fd;
	int				idx;

	if (!(0 <= fd && fd <= OPEN_MAX) || BUFFER_SIZE < 1 || !line)
		return (-1);
	chk_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chk_buf)
		return (-1);
	if (!archive[fd])
		archive[fd] = init_archive();
	idx = read(fd, chk_buf, BUFFER_SIZE);
	while (idx > 0)
	{
		chk_buf[idx] = 0;
		line_fd = attach_buf(archive[fd], chk_buf);
		archive[fd] = line_fd;
		if (ft_strchr(archive[fd], '\n'))
			break ;
		idx = read(fd, chk_buf, BUFFER_SIZE);
	}
	free(chk_buf);
	return (get_result(line, &archive[fd], idx));
}
