/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:10:11 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/14 16:10:12 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	**start_program(void)
{
	static void	*mlx;

	return (&mlx);
}

void	**wind_new(void)
{
	static void	*mlx_window;

	return (&mlx_window);
}

t_wind	window_size(char **map)
{
	t_wind	window;
	int		x;
	int		y;

	y = 0;
	x = ft_strlen(map[y]) - 1;
	while (map[y])
		y++;
	window.lenght = x * 64;
	window.width = y * 64;
	return (window);
}

void	wind_open(void)
{
	void	*mlx;
	t_wind	size_w;

	mlx = (*start_program());
	size_w = window_size((*arr_map()));
	(*wind_new()) = mlx_new_window(mlx, size_w.lenght, size_w.width, "PAC-MAN");
}
