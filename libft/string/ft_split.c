/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:48:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/03 01:06:18 by bigo             ###   ########.fr       */
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
	strnew = gc_alloc((len + 1), sizeof(char));
	if (strnew == NULL)
		return (NULL);
	while (j < len)
	{
		strnew[j] = str[*i];
		j++;
		*i += 1;
	}
	strnew[j] = '\0';
	return (strnew);
}

static void	ft_noleaks(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i])
		{
			gc_free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		gc_free(tab);
		tab = NULL;
	}
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
	tab = gc_alloc((tab_size + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (i < tab_size)
	{
		tab[i] = ft_cut_split((char *)str, c, &offset);
		if (tab[i] == NULL)
		{
			ft_noleaks(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
