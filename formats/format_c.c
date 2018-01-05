/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:22:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/25 18:22:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	format_c(t_specinfo *info, int *len, va_list *args)
{
	if (info->format == 'c' || info->format == 'C')
		format_c_putchar(info, len, (unsigned char)va_arg(*args, int));
	else
		format_c_putwchar(info, len, va_arg(*args, wchar_t));
}

void	format_c_putchar(t_specinfo *info, int *len, unsigned char c)
{
	int 	width;

	width = (info->min_width > 1) ? info->min_width - 1: 0;
	if (info->zero_minus == '-')
	{
		write(1, &c, 1);
		ft_putnchar(' ', width);
	}
	else
	{
		ft_putnchar((info->zero_minus == '0') ? '0' : ' ', width);
		write(1, &c, 1);
	}
	*len += width + 1;
}

void	format_c_putwchar(t_specinfo *info, int *len, wchar_t wc)
{
	int		wc_len;
	int 	space_len;

	wc_len = ft_utf8_bytelen(wc);
	space_len = (info->min_width > wc_len) ? (info->min_width - wc_len) : 0;
	if (info->zero_minus == '-')
	{
		ft_putwchar(wc);
		ft_putnchar(' ', space_len);
	}
	else
	{
		ft_putnchar((info->zero_minus == '0') ? '0' : ' ', space_len);
		ft_putwchar(wc);
	}
	*len += wc_len + space_len;
}