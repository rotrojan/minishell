/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:12:14 by lucocozz          #+#    #+#             */
/*   Updated: 2021/09/08 18:52:32 by rotrojan         ###   ########.fr       */
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
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strjoin(sep, s2, ""));
	}
	if (!s2)
		return (ft_strjoin(s1, sep, ""));
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = gc_malloc(sizeof(char) * (size + 1));
	ft_strcpy(strnew, (char *)s1);
	ft_strcat(strnew, (char *)sep);
	ft_strcat(strnew, (char *)s2);
	return (strnew);
}
