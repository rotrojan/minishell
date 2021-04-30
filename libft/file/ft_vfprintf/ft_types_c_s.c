/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:45:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_c(va_list ap, t_printf data, t_buffer *buffer)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (data.padding)
	{
		ft_insert_format(buffer, &data, c);
		while (data.width > 0)
			ft_insert_format(buffer, &data, ' ');
	}
	else
	{
		while (data.width > 1)
			ft_insert_format(buffer, &data, data.fill);
		ft_insert_format(buffer, &data, c);
	}
}

static void	ft_rigth_padding(t_printf data, t_buffer *buffer, char *str)
{
	int	i;

	i = 0;
	if (data.precision == -1)
		while (str[i])
			ft_insert_format(buffer, &data, str[i++]);
	else
		while (str[i] && data.precision-- > 0)
			ft_insert_format(buffer, &data, str[i++]);
	while (data.width > 0)
		ft_insert_format(buffer, &data, ' ');
}

static void	ft_left_padding(t_printf data, t_buffer *buffer, char *str)
{
	int	i;
	int	len;
	int	t_len;

	i = 0;
	t_len = ft_strlen(str);
	if (data.precision == -1)
		len = t_len;
	else
	{
		if (t_len < data.precision)
			len = t_len;
		else
			len = data.precision;
	}
	while (data.width > len)
		ft_insert_format(buffer, &data, data.fill);
	while (len-- > 0)
		ft_insert_in_buffer(buffer, str[i++]);
}

void	ft_s(va_list ap, t_printf data, t_buffer *buffer)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (data.padding)
		ft_rigth_padding(data, buffer, str);
	else
		ft_left_padding(data, buffer, str);
}
