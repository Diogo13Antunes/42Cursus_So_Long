/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:34:51 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 17:03:43 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_rotate_move(t_pict pictures, int rotation)
{
	if (rotation == 0)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.ghost1.img, (*enemy_pos('x')) * 64,
			(*enemy_pos('y')) * 64);
	else if (rotation == 1)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.ghost2.img, (*enemy_pos('x')) * 64,
			(*enemy_pos('y')) * 64);
	else if (rotation == 2)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.ghost3.img, (*enemy_pos('x')) * 64,
			(*enemy_pos('y')) * 64);
	else if (rotation == 3)
		mlx_put_image_to_window((*start_program()), (*wind_new()),
			pictures.ghost4.img, (*enemy_pos('x')) * 64,
			(*enemy_pos('y')) * 64);
}

void	do_move_enemy(t_pict pict)
{
	mlx_put_image_to_window((*start_program()), (*wind_new()),
		pict.ground.img, (*enemy_pos('x')) * 64,
		(*enemy_pos('y')) * 64);
	return ;
}

int	enemy_make_move(t_map map, int new_x, int new_y, int rotation)
{
	int			x;
	int			y;

	x = (*enemy_pos('x'));
	y = (*enemy_pos('y'));
	do_move_enemy(map.pictures);
	if ((map.map)[y + new_y][x + new_x] != '1'
		&& (map.map)[y + new_y][x + new_x] != 'e'
		&& (map.map)[y + new_y][x + new_x] != 'E'
		&& (map.map)[y + new_y][x + new_x] != 'C')
	{
		if ((map.map)[y + new_y][x + new_x] == 'P')
			leave_game(map.pictures);
		(map.map)[y + new_y][x + new_x] = 'X';
		(map.map)[y][x] = '0';
		(*enemy_pos('x')) = x + new_x;
		(*enemy_pos('y')) = y + new_y;
		enemy_rotate_move(map.pictures, rotation);
		return (1);
	}
	return (0);
}

int	exist_enemy(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x] != '\n')
		{
			if (map.map[y][x] == 'X')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}
