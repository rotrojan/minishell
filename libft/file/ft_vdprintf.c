/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:10:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/07 21:03:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		len;
	char	*str;

	str = vformat(format, ap);
	len = ft_putstr_fd(str, fd);
	gc_free(str);
	return (len);
}
