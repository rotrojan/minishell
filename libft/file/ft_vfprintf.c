/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:10:53 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/03 16:11:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vfprintf(int fd, const char *format, va_list ap)
{
	int		len;
	char	*str;

	str = vformat(format, ap);
	len = ft_putstr_fd(fd, str);
	gc_free(str);
	return (len);
}
