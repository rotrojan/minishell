/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/11 16:01:50 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_len_without_quotes(char *str)
{
	bool	in_squotes;
	bool	in_dquotes;
	int		i;
	int		len;

	in_squotes = false;
	in_dquotes = false;
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (in_dquotes == false && str[i] == '\'')
			in_squotes = (in_squotes == false);
		else if (in_squotes == false && str[i] == '"')
			in_dquotes = (in_dquotes == false);
		else
			++len;
		++i;
	}
	return (len);
}

char	*remove_quotes(char *str)
{
	bool	in_squotes;
	bool	in_dquotes;
	int		i;
	int		j;
	char	*without_quotes;

	in_squotes = false;
	in_dquotes = false;
	i = 0;
	j = 0;
	without_quotes = gc_malloc(sizeof(*without_quotes)
			* (get_len_without_quotes(str) + 1));
	while (str[i] != '\0')
	{
		if (in_dquotes == false && str[i] == '\'')
			in_squotes = (in_squotes == false);
		else if (in_squotes == false && str[i] == '"')
			in_dquotes = (in_dquotes == false);
		else
			without_quotes[j++] = str[i];
		++i;
	}
	return (without_quotes);
}
