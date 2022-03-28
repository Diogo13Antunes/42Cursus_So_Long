/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:11:54 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/17 14:39:02 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	t_data	data;
	va_list	ap;

	i = 0;
	data.count = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == 92)
			ft_putescapes(format, i);
		else if (format[i] == 37)
		{
			i = ft_putvar(ap, format, i, &data);
		}
		else
			write(1, &format[i], 1);
		i++;
		data.count++;
	}
	va_end(ap);
	return (data.count);
}
