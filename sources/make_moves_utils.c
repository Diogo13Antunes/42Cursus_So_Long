/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:31:38 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/17 11:18:03 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	make_rotation(int keycode)
{
	int	rotation;

	rotation = -1;
	if (keycode == 13)
		rotation = 13;
	else if (keycode == 0)
		rotation = 0;
	else if (keycode == 1)
		rotation = 1;
	else if (keycode == 2)
		rotation = 2;
	return (rotation);
}
