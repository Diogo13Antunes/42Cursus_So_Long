/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putescapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:43:17 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/15 12:00:03 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putescapes(const char *text, int loc)
{
	if (text[loc] == 92 && text[loc + 1] == 'a')
		write (1, "\a", 1);
	else if (text[loc] == 92 && text[loc + 1] == 'b')
		write (1, "\b", 1);
	else if (text[loc] == 92 && text[loc + 1] == 'f')
		write (1, "\f", 1);
	else if (text[loc] == 92 && text[loc + 1] == 'n')
		write (1, "\n", 1);
	else if (text[loc] == 92 && text[loc + 1] == 'r')
		write (1, "\r", 1);
	else if (text[loc] == 92 && text[loc + 1] == 't')
		write (1, "\t", 1);
	else if (text[loc] == 92 && text[loc + 1] == 'v')
		write (1, "\v", 1);
	else if (text[loc] == 92 && text[loc + 1] == 39)
		write (1, "\'", 1);
	else if (text[loc] == 92)
		write (1, "\\", 1);
	return (loc);
}
