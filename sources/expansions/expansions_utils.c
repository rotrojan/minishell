/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:53:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/09/13 15:13:23 by rotrojan         ###   ########.fr       */
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

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		gc_free((void **)&(*array)[i]);
		++i;
	}
}

int	get_len_array(char	**array)
{
	int	len;

	len = 0;
	while (array[len] != NULL)
		++len;
	return (len);
}

char	*get_after_var(char *str, int index_dollar)
{
	char	*ptr;

	ptr = str + index_dollar + 1;
	while (ft_isalnum(*ptr) == 1)
		++ptr;
	return (ptr);
}

bool	has_space(char *str)
{
	while (*str != '\0')
		if (ft_isspace(*(str++)))
			return (true);
	return (false);
}