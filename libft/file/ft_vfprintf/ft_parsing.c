/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:36:30 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 01:21:16 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_padding(char c, t_printf *data)
{
	int	pad;

	if (c == '-')
		pad = 1;
	else
		pad = 0;
	data->padding = pad;
	if (pad)
		data->fill = ' ';
	return (pad);
}

int	ft_parse_fill(char c, t_printf *data)
{
	int	fill;

	if (c == '0')
		fill = 1;
	else
		fill = 0;
	if (fill && data->precision == -1)
		data->fill = '0';
	else
		data->fill = ' ';
	return (fill);
}

int	ft_parse_width(const char *s, t_printf *data, va_list ap)
{
	int	i;
	int	nb;

	i = 0;
	if (s[i] == '*')
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width *= -1;
			ft_parse_padding('-', data);
		}
		i++;
	}
	else
	{
		nb = ft_atoi(s);
		if (nb < 0)
			data->width = nb * -1;
		else
			data->width = nb;
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int	ft_parse_precision(const char *s, t_printf *data, va_list ap)
{
	int	i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			data->precision = va_arg(ap, int);
			if (data->precision < 0)
				data->precision = -1;
			i++;
		}
		else
			data->precision = ft_atoui(&s[i]);
		if (data->precision < 0 && data->fill == '0')
			data->fill = '0';
		else
			data->fill = ' ';
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}
