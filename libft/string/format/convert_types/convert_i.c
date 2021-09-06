/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:23:58 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/03 02:50:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_i(t_fbuffer *format, va_list ap)
{
	int		len;
	int		value;
	char	*str;

	value = va_arg(ap, int);
	str = ft_itoa(value);
	len = ft_strlen(str);
	ft_strncpy(&format->buffer[format->i], str, len);
	format->i += len;
	gc_free(str);
}
