/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:53:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/15 19:08:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_quote_state(char quote, bool *in_squotes, bool *in_dquotes)
{
	if (quote == '\'' && *in_dquotes == false)
		*in_squotes = (*in_squotes == false);
	else if (quote == '"' && *in_squotes == false)
		*in_dquotes = (*in_dquotes == false);
}

char	*get_after_var(char *str, int index_dollar)
{
	char	*ptr;

	ptr = str + index_dollar + 1;
	while (ft_isalnum(*ptr) == 1)
		++ptr;
	return (ptr);
}

int	get_len_var_name(char *arg)
{
	int	len;

	len = 0;
	while (ft_isalnum(arg[len]) != 0 && arg[len] != '\0')
		++len;
	return (len);
}

char	*get_var_name(char *arg, int i)
{
	int		j;
	char	*var_name;

	j = 0;
	++i;
	var_name = gc_malloc(sizeof(*var_name) * (get_len_var_name(arg + i) + 1));
	while (ft_isalnum(arg[i]) != 0 && arg[i] != '\0')
	{
		var_name[j] = arg[i];
		++i;
		++j;
	}
	var_name[j] = '\0';
	return (var_name);
}
