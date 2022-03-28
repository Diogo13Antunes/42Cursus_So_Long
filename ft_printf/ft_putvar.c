/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:46:12 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/26 11:51:59 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvar(va_list ap, const char *text, int i, t_data *data)
{
	if (text[i] == 37 && text[i + 1] == '%')
		ft_putchar('%');
	else if (text[i] == 37 && text[i + 1] == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (text[i] == 37 && (text[i + 1] == 'd' || text[i + 1] == 'i'))
		ft_putnumbers((long int)va_arg(ap, int), data);
	else if (text[i] == 37 && text[i + 1] == 's')
		data->count += ft_putstr(va_arg(ap, char *));
	else if (text[i] == 37 && text[i + 1] == 'u')
		ft_putunnumbers(va_arg(ap, unsigned int), data);
	else if (text[i] == 37 && text[i + 1] == 'x')
		ft_hexnumbers((int)va_arg(ap, int), 'x', data);
	else if (text[i] == 37 && text[i + 1] == 'X')
		ft_hexnumbers((int)va_arg(ap, int), 'X', data);
	else if (text[i] == 37 && text[i + 1] == 'p')
		ft_putaddr(va_arg(ap, long int), data);
	return (i + 1);
}
