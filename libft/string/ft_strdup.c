/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:25:06 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/17 15:34:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	if (s == NULL)
		size = 1;
	else
		size = ft_strlen(s);
	dup = gc_malloc(sizeof(char) * (size + 1));
	if (s != NULL)
	{
		while (s[i])
		{
			dup[i] = s[i];
			i++;
		}
	}
	dup[i] = '\0';
	return (dup);
}
