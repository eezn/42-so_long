/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:04:55 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/29 03:25:56 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define MESSAGE 1
# define PERROR 0

/* main.c */
# define ERR_ARGS "\033[33mUsage: ./so_long <pathname>\033[0m"

/* check_map */
# define ERR_OPEN "\033[33mError: Failed to open the file.\033[0m"
# define ERR_RECT "\033[33mError: Map file is not rectangular.\033[0m"
# define ERR_ELEM "\033[33mError: Invalid element found in map file.\033[0m"
# define ERR_PLYR "\033[33mError: Map must have one starting position\033[0m"
# define ERR_COLL "\033[33mError: Map must have at least one collectible.\033[0m"
# define ERR_EXIT "\033[33mError: Map must have at least one exit.\033[0m"
# define ERR_CLOSED "\033[33mError: Map is not surrounded by walls.\033[0m"

#endif