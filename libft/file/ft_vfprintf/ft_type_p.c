/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:40:09 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:45:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rigth_padding(t_printf data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_nbrlen(nb, 16);
	ft_insert_str(buffer, &data, "0x");
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (nb || data.precision || !data.width)
		ft_insert_str(buffer, &data, str);
	while (data.width > 0)
		ft_insert_format(buffer, &data, ' ');
}

static void	ft_left_padding(t_printf data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_nbrlen(nb, 16);
	while (data.width > len + 2 && data.width > data.precision + 2)
		ft_insert_format(buffer, &data, data.fill);
	ft_insert_str(buffer, &data, "0x");
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (nb || data.precision || !data.width)
		ft_insert_str(buffer, &data, str);
}

void	ft_p(va_list ap, t_printf data, t_buffer *buffer)
{
	char		*str;
	uintptr_t	nb;

	nb = (uintptr_t)va_arg(ap, void *);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_ltoa_base((long)nb, "0123456789abcdef");
	if (data.padding)
		ft_rigth_padding(data, buffer, str, nb);
	else
		ft_left_padding(data, buffer, str, nb);
	ft_strdel(str);
}
