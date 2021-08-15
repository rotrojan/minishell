/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:14:49 by rotrojan          #+#    #+#             */
/*   Updated: 2021/08/15 18:37:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	maxlen;

	if (!s1)
		return (NULL);
	maxlen = ft_strnlen(s1, n);
	str = NULL;
	str = gc_malloc(sizeof(*str) * (maxlen + 1));
	*(str + maxlen) = '\0';
	return (ft_memcpy(str, s1, maxlen));
}
