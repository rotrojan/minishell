/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/26 16:01:54 by rotrojan         ###   ########.fr       */
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
		if ((str[i] == '\'' && in_dquotes == false)
			|| (str[i] == '"' && in_squotes == false))
			change_quote_state(str[i], &in_squotes, &in_dquotes);
		else
			++len;
		++i;
	}
	return (len);
}

static void	restore_quotes(char *str)
{
	while (*str != '\0')
	{
		if (*str < 0)
			*str *= -1;
		++str;
	}
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
		if ((str[i] == '\'' && in_dquotes == false)
			|| (str[i] == '"' && in_squotes == false))
			change_quote_state(str[i], &in_squotes, &in_dquotes);
		else
			without_quotes[j++] = str[i];
		++i;
	}
	restore_quotes(without_quotes);
	return (without_quotes);
}

void	remove_quotes_from_arg(char **arg)
{
	char	*tmp;

	tmp = remove_quotes(*arg);
	gc_free((void **)arg);
	*arg = tmp;
}
