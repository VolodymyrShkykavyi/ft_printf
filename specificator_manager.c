/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:57:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/19 16:57:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

static void	ft_specinfo_init(t_specinfo *info)
{
	info->format = 0;
	info->zero_minus = 0;
	info->plus_space = 0;
	info->sharp = 0;
	info->min_width = -1;
	info->precision = -1;
	info->mod_h = 0;
	info->mod_j = 0;
	info->mod_l = 0;
	info->mod_z = 0;
}

static void	parse_width_and_precision(t_specinfo *info, char *str, int len,
										 va_list *args)
{
	int	tmp;

	tmp = len;
	while (--tmp >= 0)
		if (ft_isdigit(*(str + tmp)) || *(str + tmp) == '*')
		{
			if (*(str + tmp) == '*')
			{
				info->min_width = va_arg(*args, int);
				break ;
			}
			while (tmp >= 0 && (ft_isdigit(*(str + tmp))))
				tmp--;
			if (*(str + tmp) != '.')
			{
				info->min_width = ft_atoi(str + tmp + 1);
				break ;
			}
		}
	tmp = len;
	while (--tmp >= 0)
		if (*(str + tmp) == '.')
		{
			info->precision = (*(str + tmp + 1) == '*') ?
							  va_arg(*args, int) : ft_atoi((str + tmp + 1));
			break ;
		}
}

static void	parse_mods_and_flags(t_specinfo *info, char *str, int len)
{
	while (--len >= 0)
	{
		if (*(str + len) == 'h')
			info->mod_h += 1;
		else if (*(str + len) == 'l')
			info->mod_l += 1;
		else if (*(str + len) == 'j')
			info->mod_j += 1;
		else if (*(str + len) == 'z')
			info->mod_z += 1;
		else if (*(str + len) == '-')
			info->zero_minus = '-';
		else if (*(str + len) == '0' && info->zero_minus != '-' &&
				!(ft_isdigit(*(str + len - 1))))
			info->zero_minus = '0';
		else if (*(str + len) == '+')
			info->plus_space = '+';
		else if (*(str + len) == ' ' && info->plus_space != '+')
			info->plus_space = ' ';
		else if (*(str + len) == '#')
			info->sharp = '#';
	}
}

static void	get_specificator_format(char *str, int *pos, t_specinfo *info)
{
	char	c;

	while (*(str + *pos))
	{
		c = *(str + *pos);
		if (ft_chrin_str(FORMAT, c))
		{
			info->format = *(str + *pos);
			break ;
		}
		if (!ft_isdigit(c) && c != '.' && !(ft_chrin_str(FLAG, c)) &&
				!(ft_chrin_str(MOD, c)) && c != '*')
			break ;
		(*pos)++;
	}
}

void		specificator_manager(char **format, int *len, va_list *args)
{
	int			pos;
	t_specinfo	info;

	ft_specinfo_init(&info);
	pos = 1;
	get_specificator_format(*format, &pos, &info);
	parse_width_and_precision(&info, *format + 1, pos - 1, args);
	parse_mods_and_flags(&info, *format + 1, pos - 1);
	if (!(info.format))
	{
		if (*(*format + pos) != '\0')
		{
			format_c_putchar(&info, len, *(*format + pos));
			pos++;
		}
		*format += pos;
		return ;
	}
	print_manager(&info, len, args);
	*format += pos + 1;
}
