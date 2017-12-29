/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:57:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/06 22:57:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	char 		*str;

	va_start(args, format);
	len = 0;
	str = (char *)format;
	while (*str)
	{
		while (*str == '%')
			specificator_manager(&str, &len, &args);
		if (!(*str))
			break ;
		/*if (*str == '{')
			ft_printf_getcolor(&str);*/
		len++;
		write(1, str, 1);
		str++;
	}
	return (len);
}
