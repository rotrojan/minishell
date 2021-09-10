/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:24:49 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/10 21:31:26 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_xl(t_fbuffer *format, va_list ap)
{
	int		len;
	int		value;
	char	*str;

	value = va_arg(ap, int);
	str = ft_ltoa_base(value, BASE_16L);
	len = ft_strlen(str);
	ft_strncpy(&format->buffer[format->i], str, len);
	format->i += len;
	gc_free((void **)&str);
}
