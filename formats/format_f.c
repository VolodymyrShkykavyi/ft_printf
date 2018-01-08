/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:13:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/08 15:13:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_f(t_specinfo *info, int *len, va_list *args)
{
	long double	num;

	if (info->mod_L)
		num = va_arg(*args, long double);
	else
		num = va_arg(*args, double);
}