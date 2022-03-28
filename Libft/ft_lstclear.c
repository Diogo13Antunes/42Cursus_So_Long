/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:58:37 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/18 16:03:51 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		free ((*lst)->content);
		free (*lst);
		*lst = aux;
	}
	lst = 0;
}
