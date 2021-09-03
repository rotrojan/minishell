/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:17:05 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/02 21:11:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_c(t_fbuffer *format, va_list ap)
{
	int	c;

	c = (char)va_arg(ap, int);
	format->buffer[format->i++] = c;
}
