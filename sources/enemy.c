/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:48:29 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 17:32:51 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*enemy_pos(char choice)
{
	static int	x;
	static int	y;

	if (choice == 'x')
		return (&x);
	else if (choice == 'y')
		return (&y);
	else
		return (0);
}

void	get_enemy_pos(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ((*arr_map())[y] != NULL)
	{
		x = 0;
		while ((*arr_map())[y][x] != '\n')
		{
			if ((*arr_map())[y][x] == 'X')
			{
				(*enemy_pos('x')) = x;
				(*enemy_pos('y')) = y;
			}
			x++;
		}
		y++;
	}
}

void	enemy_do_action(t_map map, int y, int x, int choice)
{
	static int	ii;

	while (ii < 5000)
	{
		ii++;
		return ;
	}
	ii = 0;
	enemy_make_move(map, y, x, choice);
}

void	enemy_move(t_map map)
{
	int	pos;

	pos = rand() % 4;
	if (pos == 0)
		enemy_do_action(map, 0, 1, 0);
	else if (pos == 1)
		enemy_do_action(map, 0, -1, 1);
	else if (pos == 2)
		enemy_do_action(map, -1, 0, 2);
	else if (pos == 3)
		enemy_do_action(map, 1, 0, 3);
	else
		return ;
}

int	enemy(t_map *map)
{
	if (exist_enemy(*map) != TRUE)
		return (0);
	get_enemy_pos();
	enemy_move(*map);
	return (0);
}
