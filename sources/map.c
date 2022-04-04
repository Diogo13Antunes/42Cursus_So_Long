/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:13:59 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/04 10:42:31 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map(int fd)
{
	while (ft_lstadd_back(map(), ft_lstnew(get_next_line(fd))))
		;
}

void	matrix_map(void)
{
	t_list	*temp_map;
	int		y;

	y = 0;
	temp_map = (*map());
	(*arr_map()) = (char **)malloc(sizeof(char *) * (ft_lstsize(temp_map) + 1));
	if ((*arr_map()) == NULL)
	{
		ft_lstclear(map());
		exit(0);
	}
	while (temp_map)
	{
		(*arr_map())[y] = temp_map->content;
		temp_map = temp_map->next;
		y++;
	}
	(*arr_map())[y] = NULL;
}

void	map_printers(int choice)
{
	int		x;
	t_list	*temp;

	x = 0;
	temp = (*map());
	if (choice == 1)
	{	
		while (temp)
		{
			ft_putstr(temp->content);
			temp = temp->next;
		}
	}
	else
	{
		while ((*arr_map())[x])
		{
			ft_printf("%s", (*arr_map())[x]);
			x++;
		}
	}
}
