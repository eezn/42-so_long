/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:07:06 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/18 18:55:56 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		get_next_line(int fd, char **line);

#endif