/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:01:33 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/26 11:52:17 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(long int addr, t_data *data)
{
	char	*addr_string;

	if (addr == 0)
	{
		write (1, "0x0", 3);
		data->count += 2;
		return ;
	}
	addr_string = ft_itoa_base(addr, 16);
	data->count += 1 + ft_strlen(addr_string);
	write (1, "0x", 2);
	addr_string = to_lower(addr_string);
	ft_putstr(addr_string);
	free(addr_string);
	return ;
}
