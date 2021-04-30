/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:46:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/30 23:33:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vfprintf(STDIN_FILENO, format, ap));
}
