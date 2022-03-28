/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:16:17 by dcandeia          #+#    #+#             */
/*   Updated: 2021/11/26 11:52:31 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
typedef struct s_data
{
	int	count;
}		t_data;
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int		ft_printf(const char *format, ...);
int		ft_putescapes(const char *text, int loc);
void	ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putunnumbers(int n, t_data *data);
void	ft_putnumbers(long int num, t_data *data);
int		ft_putvar(va_list ap, const char *text, int i, t_data *data);
void	ft_hexnumbers(unsigned long num, char up_down, t_data *data);
void	ft_putaddr(long int addr, t_data *data);
char	*to_lower(char *hex_num);
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#endif