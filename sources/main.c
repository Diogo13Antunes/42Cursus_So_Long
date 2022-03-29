/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:54:35 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/29 10:09:56 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key(int keycode, t_map *map)
{
	static int	rotation;
	char		*step;
	int			move;

	if (keycode == rotation)
	{
		move = map->steps;
		map->steps += make_moves(keycode, map);
		if (move != map->steps)
		{
			step = ft_itoa(map->steps);
			mlx_string_put((*start_program()), (*wind_new()),
				16, 16, 0x00FFFFFF, step);
			free(step);
		}
	}
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		rotation = make_rotation(keycode);
		wall_printing(map->pictures, keycode);
	}
	if (keycode == 53)
		leave_game(map->pictures);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		error_msg("Error\nInvalid number of arguments!\n");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		error_msg("Error\nInvalid file type!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_msg("Error\nInvalid file!\n");
	so_long(fd);
	close(fd);
}
