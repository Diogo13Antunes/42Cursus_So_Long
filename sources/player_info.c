/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:07:25 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/21 15:16:12 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*player_pos(char c)
{
	static int	x;
	static int	y;

	if (c == 'x')
		return (&x);
	else if (c == 'y')
		return (&y);
	else
		return (0);
}

int	find_player_pos(void)
{
	int	x;
	int	y;

	y = 0;
	while ((*arr_map())[y] != NULL)
	{
		x = 0;
		while ((*arr_map())[y][x] != '\n')
		{
			if ((*arr_map())[y][x] == 'P')
			{
				(*player_pos('x')) = x;
				(*player_pos('y')) = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}
