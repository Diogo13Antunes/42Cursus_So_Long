/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:25:28 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/18 13:54:49 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unputnbr(long int unnum, t_data *data)
{
	char	*num_string;

	num_string = ft_itoa_base(unnum, 10);
	data->count += ft_strlen(num_string) - 1;
	ft_putstr(num_string);
	free(num_string);
	return ;
}

void	ft_putunnumbers(int n, t_data *data)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(n * -1);
		nbr = 4294967296 - nbr;
	}
	else
		nbr = (unsigned int)n;
	ft_unputnbr(nbr, data);
	return ;
}
