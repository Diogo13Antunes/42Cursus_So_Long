/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:22 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/21 15:18:53 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_rules(void)
{
	if ((*map()) == NULL)
		error_msg("Error\nThe map is empty!\n");
	else if (check_map_build() == -1)
		error_msg("Error\nThe map is not correctly formatated!\n");
	else if (map_len() == -1)
		error_msg("Error\nThe map is not rectangular!\n");
	else if (check_top_bot() == -1 || check_border() == -1)
		error_msg("Error\nThe map is not correctly closed!\n");
	else
		check_elements();
}

int	map_len(void)
{
	size_t	len;
	size_t	len_temp;
	t_list	*temp;

	temp = (*map());
	len_temp = 0;
	len = ft_strlen(temp->content);
	while (temp != NULL)
	{
		if (temp->next != NULL)
			len_temp = ft_strlen(temp->next->content);
		if (len != len_temp)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	check_top_bot(void)
{
	t_list	*top;
	t_list	*bot;
	int		i;

	top = (*map());
	bot = ft_lstlast(top);
	i = 0;
	if (ft_strncmp(top->content, bot->content, ft_strlen(top->content)) == 0)
	{
		while ((top->content)[i] != '\n')
		{
			if ((top->content)[i] != '1')
				return (-1);
			i++;
		}
	}
	else
		return (-1);
	return (0);
}

int	check_border(void)
{
	t_list	*temp;
	size_t	len;

	temp = (*map());
	len = ft_strlen(temp->next->content);
	while (temp->next != NULL)
	{
		if ((temp->next->content)[0] != '1'
			|| (temp->next->content)[len - 2] != '1')
			return (-1);
		temp = temp->next;
	}
	return (0);
}
