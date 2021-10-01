/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:09:59 by lucocozz          #+#    #+#             */
/*   Updated: 2021/10/01 18:47:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_char(char *s1, char *s2, int *i, int *j)
{
	while (s1[*i] == s2[*j] && (s1[*i] != '\0' && s2[*j] != '\0'))
	{
		*i += 1;
		*j += 1;
	}
	if (s1[*i] != s2[*j] && s2[*j] != '*')
		return (0);
	return (1);
}

static int	match_wildcard(char *s1, char *s2, int *i, int *j)
{
	if (s2[*j] == '*')
	{
		while (s2[*j] == '*')
			*j += 1;
		while (s1[*i] != s2[*j])
		{
			if (s1[*i] == '\0' && s2[*j] != '\0')
				return (0);
			*i += 1;
		}
	}
	return (1);
}

int	match(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (match_char(s1, s2, &i, &j) == 0)
			return (0);
		if (match_wildcard(s1, s2, &i, &j) == 0)
			return (0);
	}
	if (s1[i] != s2[j])
		return (0);
	return (1);
}
