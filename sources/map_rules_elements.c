/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:27:25 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/28 17:14:35 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_build(void)
{
	t_list	*temp;
	int		i;

	temp = (*map());
	while (temp != NULL)
	{
		i = 0;
		while ((temp->content)[i] != '\n')
		{
			if ((temp->content)[i] != '1' && (temp->content)[i] != '0'
				&& (temp->content)[i] != 'C' && (temp->content)[i] != 'P'
				&& (temp->content)[i] != 'E' && (temp->content)[i] != 'X')
				return (-1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

void	check_elements(void)
{
	t_elements	elem;
	t_list		*temp;
	int			i;

	elem.c = 0;
	elem.e = 0;
	elem.p = 0;
	temp = (*map());
	while (temp->next != NULL)
	{
		i = 0;
		while ((temp->next->content)[i] != '\n')
		{
			if ((temp->next->content)[i] == 'C')
				elem.c++;
			else if ((temp->next->content)[i] == 'E')
				elem.e++;
			else if ((temp->next->content)[i] == 'P')
				elem.p++;
			i++;
		}
		temp = temp->next;
	}
	errors_elements(elem);
}

void	errors_elements(t_elements elem)
{
	if (elem.c == 0)
		error_msg("Error\nThe map needs at least 1 collectible!\n");
	else if (elem.e == 0)
		error_msg("Error\nThe map needs at least 1 exit!\n");
	else if (elem.p == 0)
		error_msg("Error\nThe map needs at least 1 starting position!\n");
	else
		ft_printf("\e[1;37mMap Verification: \e[1;32m[OK]\e[0m\n");
}
