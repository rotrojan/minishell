/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:46:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/03 16:07:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	int		len;
	char	*str;
	va_list	ap;

	va_start(ap, format);
	str = vformat(format, ap);
	len = ft_putstr_fd(fd, str);
	gc_free(str);
	return (len);
}
