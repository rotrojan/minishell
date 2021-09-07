/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:24:41 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 18:45:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_s(t_fbuffer *format, va_list ap)
{
	int			len;
	char		*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_strcpy(&format->buffer[format->i], str);
	format->i += len;
}
