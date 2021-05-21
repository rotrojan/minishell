/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:48:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 14:11:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_split(char *str, char c)
{
	int	i;
	int	nb;
	int	bl;

	i = 0;
	nb = 0;
	while (str[i])
	{
		bl = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (!bl)
				nb += 1;
			bl = 1;
			i++;
		}
	}
	return (nb);
}

static char	*ft_cut_split(char *str, char c, int *i)
{
	int		j;
	int		len;
	char	*strnew;

	j = 0;
	len = 0;
	while (str[*i] == c && str[*i])
		*i += 1;
	while (str[*i + len] != c && str[*i + len])
		len++;
	strnew = gc_malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		strnew[j] = str[*i];
		j++;
		*i += 1;
	}
	strnew[j] = '\0';
	return (strnew);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**tab;
	int		offset;
	int		tab_size;

	i = 0;
	offset = 0;
	if (!str)
		return (NULL);
	tab_size = ft_nb_split((char *)str, c);
	tab = gc_malloc(sizeof(char *) * (tab_size + 1));
	while (i < tab_size)
	{
		tab[i] = ft_cut_split((char *)str, c, &offset);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
