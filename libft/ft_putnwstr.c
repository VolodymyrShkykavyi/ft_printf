/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:03:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/29 16:03:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnwstr(wchar_t *str, size_t len)
{
	size_t	byte_output;

	byte_output = 0;
	while (len-- > 0)
	{
		ft_putwchar(*str++);
		byte_output += ft_utf8_bytelen(*str);
	}
	return (tmp);
}