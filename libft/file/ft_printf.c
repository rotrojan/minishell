/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:46:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/06 19:37:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	va_start(ap, format);
	str = vformat(format, ap);
	len = ft_putstr_fd(str, STDOUT_FILENO);
	gc_free((void **)&str);
	return (len);
}
