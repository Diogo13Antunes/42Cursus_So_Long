/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:53:24 by dcandeia          #+#    #+#             */
/*   Updated: 2022/03/22 10:01:17 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new || !lst)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
	return (*lst);
}
