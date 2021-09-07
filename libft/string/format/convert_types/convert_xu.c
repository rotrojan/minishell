/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:24:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 22:04:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_xu(t_fbuffer *format, va_list ap)
{
	int		len;
	int		value;
	char	*str;

	value = va_arg(ap, int);
	str = ft_ltoa_base(value, BASE_16U);
	len = ft_strlen(str);
	ft_strncpy(&format->buffer[format->i], str, len);
	format->i += len;
	gc_free((void **)&str);
}
