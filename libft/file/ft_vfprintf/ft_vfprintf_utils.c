/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:41:25 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:39:48 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_printf	ft_init_parse(void)
{
	t_printf	data;

	data.padding = 0;
	data.width = 0;
	data.precision = -1;
	data.fill = ' ';
	data.type = 0;
	return (data);
}

void	ft_print_buffer(t_buffer *buffer)
{
	write(buffer->fd, buffer->data, buffer->i);
	buffer->len += buffer->i;
	ft_bzero(buffer->data, VFPRINTF_BUFFER_SIZE);
	buffer->i = 0;
}

void	ft_insert_in_buffer(t_buffer *buffer, char c)
{
	buffer->data[buffer->i++] = c;
	if (buffer->i == VFPRINTF_BUFFER_SIZE - 1)
		ft_print_buffer(buffer);
}

void	ft_insert_format(t_buffer *buffer, t_printf *data, char c)
{
	ft_insert_in_buffer(buffer, c);
	data->width--;
}

void	ft_insert_str(t_buffer *buffer, t_printf *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_insert_format(buffer, data, str[i++]);
}
