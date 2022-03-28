/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:20:45 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/18 13:42:29 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_upper(char *hex_num)
{
	int	i;

	i = 0;
	if (!hex_num)
		return (0);
	while (hex_num[i])
	{
		if (hex_num[i] > 96 && hex_num[i] < 123)
			hex_num[i] -= 32;
		i++;
	}
	return (hex_num);
}

char	*to_lower(char *hex_num)
{
	int	i;

	i = 0;
	if (!hex_num)
		return (0);
	while (hex_num[i])
	{
		if (hex_num[i] > 64 && hex_num[i] < 91)
			hex_num[i] += 32;
		i++;
	}
	return (hex_num);
}

void	ft_hexnumbers(unsigned long num, char up_down, t_data *data)
{
	char	*hex_string;

	hex_string = ft_itoa_base(num, 16);
	if (up_down == 'X')
		hex_string = to_upper(hex_string);
	if (up_down == 'x')
		hex_string = to_lower(hex_string);
	data->count += ft_strlen(hex_string) - 1;
	ft_putstr(hex_string);
	free(hex_string);
	return ;
}
