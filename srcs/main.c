/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:33 by jin-lee           #+#    #+#             */
/*   Updated: 2021/11/16 16:21:52 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./images/test_img.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}