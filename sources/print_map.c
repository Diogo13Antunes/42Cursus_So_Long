/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:02:24 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 16:35:49 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	image_creator(char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image((*start_program()),
			path, &img.size, &img.size);
	return (img);
}

t_pict	pictures_creator(void)
{
	t_pict	pictures;

	pictures.wall = image_creator(I_BORDER);
	pictures.ground = image_creator(I_GROUND);
	pictures.collectible = image_creator(I_CHERRY);
	pictures.exit_close = image_creator(I_EXIT_CLOSE);
	pictures.exit_open = image_creator(I_EXIT_OPEN);
	pictures.player1 = image_creator(I_PACMAN1);
	pictures.player2 = image_creator(I_PACMAN2);
	pictures.player3 = image_creator(I_PACMAN3);
	pictures.player4 = image_creator(I_PACMAN4);
	pictures.ghost1 = image_creator(I_GHOST1);
	pictures.ghost2 = image_creator(I_GHOST2);
	pictures.ghost3 = image_creator(I_GHOST3);
	pictures.ghost4 = image_creator(I_GHOST4);
	return (pictures);
}

void	print_player(t_pict pictures, int choice)
{
	if (choice == 13)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.player4.img, (*player_pos('x')) * 64,
			(*player_pos('y')) * 64);
	else if (choice == 0)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.player3.img, (*player_pos('x')) * 64,
			(*player_pos('y')) * 64);
	else if (choice == 1)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.player2.img, (*player_pos('x')) * 64,
			(*player_pos('y')) * 64);
	else if (choice == 2)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.player1.img, (*player_pos('x')) * 64,
			(*player_pos('y')) * 64);
}

void	print_elements(t_pict pictures)
{
	int	x;
	int	y;

	y = 0;
	while ((*arr_map())[y])
	{
		x = 0;
		while ((*arr_map())[y][x] != '\n')
		{
			if ((*arr_map())[y][x] == 'C')
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.collectible.img, x * 64, y * 64);
			else if ((*arr_map())[y][x] == 'E')
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.exit_close.img, x * 64, y * 64);
			else if ((*arr_map())[y][x] == 'e')
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.exit_open.img, x * 64, y * 64);
			else if ((*arr_map())[y][x] == 'X')
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.ghost1.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	wall_printing(t_pict pictures, int keycode)
{
	int		x;
	int		y;

	y = -1;
	while ((*arr_map())[++y])
	{
		x = -1;
		while ((*arr_map())[y][++x])
		{
			if ((*arr_map())[y][x] == '1')
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.wall.img, x * 64, y * 64);
			else
				mlx_put_image_to_window((*start_program()), (*wind_new()),
					pictures.ground.img, x * 64, y * 64);
		}
	}
	print_elements(pictures);
	print_player(pictures, keycode);
}
