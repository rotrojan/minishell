/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:46:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/22 21:46:26 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_len_with_escaped_quotes(char *str)
{
	int	i;
	int	nb_quotes;

	i = 0;
	nb_quotes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '"')
			++nb_quotes;
		++i;
	}
	return (i + nb_quotes);
}

void	fill_with_escaped_quotes(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		if (src[j] == '\'' || src[j] == '"')
			dest[i++] = '\\';
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
}

void	escape_quotes(char **splitted_var)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (splitted_var[i] != NULL)
	{
		if (ft_strchr(splitted_var[i], '"') != NULL
			|| ft_strchr(splitted_var[i], '\'') != NULL)
		{
			len = get_len_with_escaped_quotes(splitted_var[i]);
			tmp = gc_malloc(sizeof(*tmp) * (len + 1));
			fill_with_escaped_quotes(tmp, splitted_var[i]);
			gc_free((void **)&splitted_var[i]);
			splitted_var[i] = tmp;
		}
		++i;
	}
}

