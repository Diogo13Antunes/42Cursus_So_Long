/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:34:34 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/18 13:39:49 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_nbr_len(unsigned long nb, int base)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	cpy = (char *)malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_itoa_base(unsigned long value, int base)
{
	int		i;
	int		s;
	int		len;
	char	*radix;
	char	*result;

	i = 0;
	s = 0;
	len = 0;
	radix = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_nbr_len(value, base);
	result = (char *)malloc(sizeof(char) * (len + s + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (len > s)
	{
		result[len - 1] = radix[value % base];
		value /= base;
		len--;
	}
	return (result);
}
