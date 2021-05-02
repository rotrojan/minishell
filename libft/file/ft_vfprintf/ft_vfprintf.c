/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:30 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/01 19:01:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_format_buffer(t_printf data, t_buffer *buffer, va_list ap)
{
	int						i;
	static const t_types	types[N_TYPES] = {
		{'%', &ft_per}, {'c', &ft_c}, {'s', &ft_s},
		{'p', &ft_p}, {'d', &ft_d}, {'i', &ft_i},
		{'u', &ft_u}, {'x', &ft_x}, {'X', &ft_xu}
	};

	i = 0;
	while (i <= N_TYPES && data.type != types[i].name)
		i++;
	types[i].function(ap, data, buffer);
}

static t_printf	ft_parsing(const char *format, int *i, va_list ap)
{
	t_printf	data;

	data = ft_init_parse();
	*i += 1;
	while (!ft_strchr(TYPES, format[*i]) && format[*i])
	{
		*i += ft_parse_padding(format[*i], &data);
		*i += ft_parse_fill(format[*i], &data);
		*i += ft_parse_width(&format[*i], &data, ap);
		*i += ft_parse_precision(&format[*i], &data, ap);
	}
	data.type = format[*i];
	*i += 1;
	return (data);
}

int	ft_vfprintf(int fd, const char *format, va_list ap)
{
	int			i;
	t_buffer	buffer;

	i = 0;
	buffer.i = 0;
	buffer.len = 0;
	buffer.fd = fd;
	while (format[i])
	{
		if (format[i] == '%')
			ft_format_buffer(ft_parsing(format, &i, ap), &buffer, ap);
		else
			ft_insert_in_buffer(&buffer, format[i++]);
	}
	ft_print_buffer(&buffer);
	return (buffer.len);
}
