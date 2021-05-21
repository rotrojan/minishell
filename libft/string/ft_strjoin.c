/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:12:14 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:12:00 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char const *sep)
{
	int		i;
	int		j;
	int		size;
	char	*strnew;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep);
	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = gc_malloc(sizeof(char) * (size + 1));
	ft_strcpy(strnew, (char *)s1);
	ft_strcat(strnew, (char *)sep);
	ft_strcat(strnew, (char *)s2);
	return (strnew);
}
