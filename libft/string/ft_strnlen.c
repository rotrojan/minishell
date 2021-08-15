/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:07:48 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/20 22:49:11 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char const *s, size_t maxlen)
{
	size_t		size;

	size = 0;
	if (!s)
		return (0);
	while (*(s + size) && maxlen--)
		size++;
	return (size);
}
