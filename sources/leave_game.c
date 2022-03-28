/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:49:47 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 16:25:33 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_mem(t_pict pictures)
{
	ft_lstclear(map());
	free((*arr_map()));
	(void)pictures;
}

int	leave_game(t_pict pictures)
{
	free_mem(pictures);
	exit(0);
	return (0);
}
