/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:31:06 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/18 13:54:17 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	absolute_value(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	get_len(long int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(long int nbr)
{
	char	*result;
	int		len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}

void	ft_putnumbers(long int num, t_data *data)
{
	char	*num_string;

	num_string = ft_itoa(num);
	data->count += ft_strlen(num_string) - 1;
	ft_putstr(num_string);
	free(num_string);
	return ;
}
