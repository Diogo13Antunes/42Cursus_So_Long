/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:54:44 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 16:34:16 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_list	**map(void)
{
	static t_list	*map;

	return (&map);
}

char	***arr_map(void)
{
	static char	**map;

	return (&map);
}

int	so_long(int fd)
{
	t_map		map;

	get_map(fd);
	check_map_rules();
	matrix_map();
	find_player_pos();
	(*start_program()) = mlx_init();
	wind_open();
	map.pictures = pictures_creator();
	map.map = (*arr_map());
	map.steps = 0;
	wall_printing(map.pictures, 2);
	mlx_loop_hook((*start_program()), enemy, &map);
	mlx_key_hook((*wind_new()), key, &map);
	mlx_hook((*wind_new()), 17, 0, leave_game, &map.pictures);
	mlx_loop((*start_program()));
	return (0);
}
