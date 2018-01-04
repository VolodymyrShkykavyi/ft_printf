/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:44:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/20 19:44:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_numlen(intmax_t number, int base)
{
	int		len;

	len = (number < 0 && base == 10) ? 1 : 0;
	if (number == 0)
		return (1);
	if (number < 0)
		number *= -1;
	while (number)
	{
		len++;
		number /= base;
	}
	return (len);
}

#include <stdio.h>
char		*ft_itoa_base(intmax_t num, int base)
{
	char	*res;
	int		len;

	len = ft_numlen(num, base);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (num < 0 && base == 10)
		res[0] = '-';
	if (num < 0)
	{
		res[len--] = HEX_SYMBOLS[-(num % base)];
		num /= base;
		num *= -1;
	}
	while (num)
	{
		res[len--] = HEX_SYMBOLS[num % base];
		num /= base;
	}
	if (len >= 0 && res[0] != '-')
		res[0] = '0';
	return (res);
}