/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 00:21:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/25 00:21:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	format_p(t_specinfo *info, int *len, va_list *args)
{
	void	*addr;
	char	*str;

	addr = va_arg(*args,uintmax_t);

	str = ft_uitoa_base(addr, 16);
	ft_str_tolower(&str);
	ft_putstr("0x");
	*len = 2 + ft_strlen(str);
	ft_putstr(str);
	free(str);
}