/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:44:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/08 20:44:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <string.h>
#include <errno.h>

void	format_m(t_specinfo *info, int *len)
{
	char	*str;

	str = strerror(errno);
	format_s_putstr(info, len, str);
}