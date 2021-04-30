/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_u_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:35:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:42:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rigth_padding(t_printf data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_strlen(str);
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (!nb && !data.precision && data.width)
		ft_insert_format(buffer, &data, ' ');
	else if (nb || data.precision)
		ft_insert_str(buffer, &data, str);
	while (data.width > 0)
		ft_insert_format(buffer, &data, ' ');
}

static void	ft_left_padding(t_printf data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_strlen(str);
	while (data.width > len && data.width > data.precision)
		ft_insert_format(buffer, &data, data.fill);
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (!nb && !data.precision && data.width)
		ft_insert_format(buffer, &data, ' ');
	else if (nb || data.precision)
		ft_insert_str(buffer, &data, str);
}

void	ft_u(va_list ap, t_printf data, t_buffer *buffer)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(ap, unsigned int);
	str = ft_uitoa(nb);
	if (data.padding)
		ft_rigth_padding(data, buffer, str, nb);
	else
		ft_left_padding(data, buffer, str, nb);
	ft_strdel(str);
}

void	ft_per(va_list ap, t_printf data, t_buffer *buffer)
{
	(void)ap;
	(void)data;
	ft_insert_in_buffer(buffer, '%');
}
