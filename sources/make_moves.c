/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:34:37 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 16:27:19 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*open_exits(t_map *map, int key)
{
	int	a;
	int	aa;
	int	items;

	a = 0;
	items = 0;
	while ((map->map)[a])
	{
		aa = 0;
		while ((map->map)[a][aa])
		{
			if ((map->map)[a][aa] == 'E')
				(map->map)[a][aa] = 'e';
			aa++;
		}
		a++;
	}
	wall_printing(map->pictures, key);
	return (map);
}

int	get_items(t_map *map)
{
	int	a;
	int	aa;
	int	items;

	a = 0;
	items = 0;
	while ((map->map)[a])
	{
		aa = 0;
		while ((map->map)[a][aa])
		{
			if ((map->map)[a][aa] == 'C')
				items++;
			aa++;
		}
		a++;
	}
	return (items);
}

int	refresh_position(int new_y, int new_x, t_map *map, int key)
{
	static int	items;
	int			x;
	int			y;

	items = get_items(map);
	x = (*player_pos('x'));
	y = (*player_pos('y'));
	if ((map->map)[y + new_y][x + new_x] != '1'
		&& (map->map)[y + new_y][x + new_x] != 'E')
	{
		if ((map->map)[y + new_y][x + new_x] == 'C')
			items--;
		if ((map->map)[y + new_y][x + new_x] == 'e'
			|| (map->map)[y + new_y][x + new_x] == 'X')
			leave_game(map->pictures);
		(map->map)[y + new_y][x + new_x] = 'P';
		(map->map)[y][x] = '0';
		(*player_pos('x')) = x + new_x;
		(*player_pos('y')) = y + new_y;
		if (items == 0)
			open_exits(map, key);
		return (1);
	}
	return (0);
}

int	move(int y, int x, t_map *map, int key)
{
	int	steps;

	steps = 0;
	steps += refresh_position(y, x, map, key);
	if (steps == 1)
	{
		mlx_clear_window((*start_program()), (*wind_new()));
		wall_printing(map->pictures, key);
	}
	return (steps);
}

int	make_moves(int keycode, t_map *map)
{
	int	steps;

	steps = 0;
	if (keycode == 13)
		steps = move(-1, 0, map, keycode);
	else if (keycode == 0)
		steps = move(0, -1, map, keycode);
	else if (keycode == 1)
		steps = move(1, 0, map, keycode);
	else if (keycode == 2)
		steps = move(0, 1, map, keycode);
	return (steps);
}
