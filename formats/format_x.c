/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/05 13:16:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void format_x_print(t_specinfo *info, char *str, short str_len, short space_len)
{
	if (info->zero_minus != '-')
		ft_putnchar(' ', space_len);
	if (info->sharp)
	{
		ft_putchar('0');
		ft_putchar((info->format == 'x') ? 'x' : 'X');
	}
	ft_putnchar('0', str_len - ft_strlen(str));
	ft_putstr(str);
	if (info->zero_minus == '-')
		ft_putnchar(' ', space_len);
}

#include <stdio.h>
#include <unistd.h>
void	format_x(t_specinfo *info, int *len, va_list *args)
{
	uintmax_t	num;
	char		*str;
	short		space_len;
	short		str_len;

	ft_printf_cast_unum(info, &num, args);

	str = (!num && !(info->precision)) ? ft_strnew(0) : ft_uitoa_base(num, 16);
	if (info->format == 'x')
		ft_str_tolower(&str);
	else
		ft_str_toupper(&str);
	str_len = ft_strlen(str);
	str_len = (info->precision > str_len) ? info->precision : str_len;
	if (info->sharp && num != 0)
		str_len += 2;
	space_len = (info->min_width > str_len) ? info->min_width - str_len : 0;
	*len += space_len + str_len;
	if (info->sharp && num != 0)
		str_len -= 2;
	format_x_print(info, str, str_len, space_len);
	free(str);
}